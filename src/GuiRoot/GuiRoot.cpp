#include "GuiRoot.h"

#include "Components/ComponentFactory.h"

#include <GL/freeglut.h>
#include <semaphore.h>
#include <unistd.h>
#include <fstream>

// NOLINTNEXTLINE: Allow non-const global variable as it is file scoped using
// static
static ComponentFactory factory;

// NOLINTNEXTLINE: Allow non-const global variable as it is file scoped using
// static
static GamePageModel gamePageModel(&factory);  // NOLINT
// NOLINTNEXTLINE: Allow non-const global variable as it is file scoped using
// static
static GamePageView gamePageView(&gamePageModel);  // NOLINT
// NOLINTNEXTLINE: Allow non-const global variable as it is file scoped using
// static
static GamePageController gamePageController(&gamePageView, &gamePageModel);

// NOLINTNEXTLINE: Allow non-const global variable as it is file scoped using
// static
static sem_t lock;  // NOLINT
// NOLINTNEXTLINE: Allow non-const global variable as it is file scoped using
// static
static sem_t gameStartLock;  // NOLINT

constexpr unsigned screenResolutionX = 640;
constexpr unsigned screenResolutionY = 480;
constexpr unsigned windowPositionX = 150;
constexpr unsigned windowPositionY = 50;

void* startGlutMainLoop(void* /*unused*/) {
  sem_wait(&gameStartLock);
  glutMainLoop();
  return nullptr;
}

static void resize(int width, int height) {
  /*
  Handle what happens when OpenGL window is resized
  */
  const float ar = (float)width / (float)height;

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);  // NOLINT

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void idle_State() {
  gamePageController.idleStateHandler();
  if (gamePageModel.isGameOver()) {
    sem_post(&lock);
    sem_wait(&gameStartLock);
  }
}

void display() { gamePageView.render(); }

void keyPressed(unsigned char key, int x, int y) {
  gamePageController.keyPressed(key, x, y);
}

void keyReleased(unsigned char key, int x, int y) {
  gamePageController.keyReleased(key, x, y);
}

GuiRoot* GuiRoot::instance = nullptr;  // NOLINT false positive

GuiRoot::GuiRoot() : opt_Page(false), model(nullptr) {
  // Initialize SDL2 with video and audio
  // TODO: handle error
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    ;
  }

  this->gWindow =
      SDL_CreateWindow("FLAPPY BIRDS", windowPositionX, windowPositionY,
                       screenResolutionX, screenResolutionY, SDL_WINDOW_SHOWN);
  // TODO: handle error
  if (gWindow == NULL) {
    ;
  }

  this->gScreenSurface = SDL_GetWindowSurface(gWindow);  // Get window surface

  // NOLINTNEXTLINE raw pointer deleted manually
  this->startPageModel = new StartPageModel;
  // NOLINTNEXTLINE raw pointer deleted manually
  this->startPageView =
      new StartPageView(gWindow, gScreenSurface, startPageModel);
  // NOLINTNEXTLINE raw pointer deleted manually
  this->startPageController =
      new StartPageController(startPageView, startPageModel);

  // NOLINTNEXTLINE raw pointer deleted manually
  this->optionsPageModel = new OptionsPageModel;
  // NOLINTNEXTLINE raw pointer deleted manually
  this->optionsPageView =
      new OptionsPageView(gWindow, gScreenSurface, optionsPageModel);
  // NOLINTNEXTLINE raw pointer deleted manually
  this->optionsPageController =
      new OptionsPageController(optionsPageView, optionsPageModel);

  this->view = startPageView;
  this->controller = startPageController;

  gamePageModel.pauseGame();

  this->initOpenGl();
}

GuiRoot::~GuiRoot() {
  if (gWindow != nullptr) {
    SDL_DestroyWindow(gWindow);  // Destroy window
  }
  gWindow = nullptr;

  SDL_Quit();  // Quit SDL subsystems
}

void GuiRoot::render() { this->view->render(); }

void GuiRoot::runGame() {
  SDL_HideWindow(gWindow);
  glutShowWindow();
  sem_post(&gameStartLock);
  gamePageModel.resumeGame();
  // Wait until game ends
  sem_wait(&lock);
  onGameOver();
  gamePageModel = GamePageModel(&factory);
  SDL_ShowWindow(gWindow);
}

void GuiRoot::run() {
  this->render();

  SDL_Event e;  // Event handler

  // While application is running
  while (true) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      if (controller->handleEvent(e)) {
        continue;
      }
      if (this->handleEvent(e)) {
        continue;
      }
      return;
    }
  }
}

bool GuiRoot::handleEvent(SDL_Event& e) {
  if (e.type == SDL_QUIT) {
    musicPlayer.stop();
    return false;
  }
  if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {
      case SDLK_RETURN:
        if (!opt_Page) {
          switch (startPageModel->getCursorPosition()) {
            case 1:
              runGame();
              break;
            case 2:
              opt_Page = true;
              view = optionsPageView;
              controller = optionsPageController;
              break;
            case 0:
              musicPlayer.stop();
              return false;
          }
        }
        break;
      case SDLK_ESCAPE:
        if (opt_Page) {
          opt_Page = false;
          view = startPageView;
          controller = startPageController;
        }
        break;
    }
    view->render();
  }
  return true;
}

void GuiRoot::onGameOver() {
  std::ifstream score_File("../res/scores.data", std::ios::in);

  unsigned numScores = 0;
  score_File >> numScores;

  std::vector<unsigned> highScores(numScores);
  for (int i = 0; i < numScores; i++) {
    score_File >> highScores[i];
  }

  score_File.close();

  highScores.push_back(gamePageModel.getScoreBoard().getScore());
  std::sort(highScores.begin(), highScores.end(), std::greater<>());

  constexpr unsigned maxNumScoresStorable = 10;
  if (numScores >= maxNumScoresStorable) {
    highScores.pop_back();
  } else {
    numScores += 1;
  }

  std::ofstream score_File_Out("../res/scores.data", std::ios::out);
  score_File_Out << numScores << std::endl;
  for (int i = 0; i < numScores; i++) {
    score_File_Out << highScores[i] << std::endl;
  }
  score_File.close();
}

GuiRoot* GuiRoot::getInstance() {
  if (instance == nullptr) {
    instance = new GuiRoot;  // NOLINT
  }
  return instance;
}

void GuiRoot::initOpenGl() {
  // Transition to complete OPENGL to handle game play and related graphics

  static bool alreadyInitialized = false;

  if (alreadyInitialized) {
    glutShowWindow();
    return;
  }

  // Dummy arguments passed to OpenGL
  int argc = 1;                    // NOLINT
  char* argv[1] = {(char*)"app"};  // NOLINT

  // Initialize glut with arguments passed
  glutInit(&argc, argv);  // NOLINT
  glutInitDisplayMode(GLUT_SINGLE |
                      GLUT_RGBA);  // Set the display mode to single buffering
                                   // and RGBA(Alpha) mode
  glutReshapeFunc(resize);  // Function to scale and get diplay ratios according
                            // to new dimensions
  glutInitWindowPosition(windowPositionX,
                         windowPositionY);  // Set the window position
  glutInitWindowSize(
      screenResolutionX,
      screenResolutionY);            // Set the window size, measured in pixels
  glutCreateWindow("FLAPPY BIRDS");  // Set window title
  glutDisplayFunc(
      display);  // Register a callback func. to handle what to display
  glutKeyboardFunc(
      keyPressed);  // Register a callback func. to handle key-presses
  glutKeyboardUpFunc(
      keyReleased);          // Register a callback func. to handle key-releases
  glutIdleFunc(idle_State);  // Register a callback func. to handle idle
                             // situations(Nothing has happened during loop)
  glutHideWindow();

  // Start main loop in a separate thread
  int threadId = pthread_create(&this->glutMailLoopThread, nullptr,
                                startGlutMainLoop, nullptr);

  if (threadId != 0) {
    // TODO: Handle error
  }

  alreadyInitialized = true;
}
