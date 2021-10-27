#include "GuiRoot.h"

#include "AudioEngine.h"

#include <GL/freeglut.h>
#include <unistd.h>

GamePageModel gamePageModel;
GamePageView gamePageView(&gamePageModel);
GamePageController gamePageController(&gamePageView, &gamePageModel);

static void resize(int width, int height) {
  /*
  Handle what happens when OpenGL window is resized
  */
  const float ar = (float)width / (float)height;

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void idle_State() { gamePageController.idleStateHandler(); }

void display() { gamePageView.render(); }

void keyPressed(unsigned char key, int x, int y) {
  gamePageController.keyPressed(key, x, y);
}

void keyReleased(unsigned char key, int x, int y) {
  gamePageController.keyReleased(key, x, y);
}

GuiRoot* GuiRoot::instance = nullptr;

GuiRoot::GuiRoot() {
  // Initialize SDL2 with video and audio
  // TODO: handle error
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    ;

  gamePageModel.pauseGame();

  this->gWindow =
      SDL_CreateWindow("FLAPPY BIRDS", 150, 50, 640, 480, SDL_WINDOW_SHOWN);
  // TODO: handle error
  if (gWindow == NULL)
    ;

  this->gScreenSurface = SDL_GetWindowSurface(gWindow);  // Get window surface

  this->startPageModel = new StartPageModel;
  this->startPageView =
      new StartPageView(gWindow, gScreenSurface, startPageModel);
  this->startPageController =
      new StartPageController(startPageView, startPageModel);

  this->optionsPageModel = new OptionsPageModel;
  this->optionsPageView =
      new OptionsPageView(gWindow, gScreenSurface, optionsPageModel);
  this->optionsPageController =
      new OptionsPageController(optionsPageView, optionsPageModel);

  this->view = startPageView;
  this->controller = startPageController;
}

GuiRoot::~GuiRoot() {
  SDL_DestroyWindow(gWindow);  // Destroy window
  gWindow = NULL;
  SDL_Quit();  // Quit SDL subsystems
  delete instance;
}

void GuiRoot::render() { this->view->render(); }

void GuiRoot::handleEvents() {
  // INPUT_HANDLER:
  SDL_Event e;  // Event handler

  // While application is running
  while (true) {
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
      if (controller->handleEvent(e)) {
        continue;
      } else {
        if (e.type == SDL_QUIT) {
          // Quit application
          stop_Music();
          return;
        } else if (e.type == SDL_KEYDOWN) {
          switch (e.key.keysym.sym) {
            case SDLK_RETURN:
              if (!opt_Page) {
                switch (startPageModel->getCursorPosition()) {
                  case 1:
                    // goto EXIT_SDL;
                    SDL_HideWindow(gWindow);
                    this->initOpenGl();
                    gamePageModel.resumeGame();
                    // Wait until game ends
                    while (!gamePageModel.isGameOver())
                      ;
                    sleep(1);
                    gamePageModel = GamePageModel();
                    SDL_ShowWindow(gWindow);
                    view->render();
                    break;
                  case 2:
                    opt_Page = true;
                    view = optionsPageView;
                    controller = optionsPageController;
                    view->render();
                    break;
                  case 0:
                    // Quit application
                    stop_Music();
                    return;
                }
              }
              break;
            case SDLK_ESCAPE:
              if (opt_Page) {
                opt_Page = false;
                view = startPageView;
                controller = startPageController;

                view->render();
              }
              break;
          }
        }
      }
    }
  }
}

GuiRoot* GuiRoot::getInstance() {
  if (instance == nullptr) {
    instance = new GuiRoot;
  }
  return instance;
}

void* startGlutMainLoop(void*) {
  glutMainLoop();
  return nullptr;
}

void GuiRoot::initOpenGl() {
  // Transition to complete OPENGL to handle game play and related graphics

  static bool alreadyInitialized = false;

  if (alreadyInitialized) {
    glutShowWindow();
    return;
  }

  // Dummy arguments passed to OpenGL
  int argc = 1;
  char* argv[1] = {(char*)"app"};

  // Initialize glut with arguments passed
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE |
                      GLUT_RGBA);  // Set the display mode to single buffering
                                   // and RGBA(Alpha) mode
  glutReshapeFunc(resize);  // Function to scale and get diplay ratios according
                            // to new dimensions
  glutInitWindowPosition(150, 50);   // Set the window position
  glutInitWindowSize(640, 480);      // Set the window size, measured in pixels
  glutCreateWindow("FLAPPY BIRDS");  // Set window title
  glutDisplayFunc(
      display);  // Register a callback func. to handle what to display
  glutKeyboardFunc(
      keyPressed);  // Register a callback func. to handle key-presses
  glutKeyboardUpFunc(
      keyReleased);          // Register a callback func. to handle key-releases
  glutIdleFunc(idle_State);  // Register a callback func. to handle idle
                             // situations(Nothing has happened during loop)

  // Start main loop in a separate thread
  int threadId = pthread_create(&this->glutMailLoopThread, nullptr,
                                startGlutMainLoop, nullptr);

  alreadyInitialized = true;
}
