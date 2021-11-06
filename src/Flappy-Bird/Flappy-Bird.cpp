#include "Flappy-Bird.h"

#include "StartPage/controller.h"
#include "StartPage/model.h"
#include "StartPage/view.h"

#include "OptionsPage/controller.h"
#include "OptionsPage/model.h"
#include "OptionsPage/view.h"

#include "GamePage/controller.h"
#include "GamePage/model.h"
#include "GamePage/view.h"

#include "ResultPage/view.h"

#include "Components/ComponentFactory.h"

#include <SDL2/SDL_opengl.h>
#include <semaphore.h>
#include <unistd.h>
#include <algorithm>
#include <fstream>

constexpr unsigned screenResolutionX = 640;
constexpr unsigned screenResolutionY = 480;
constexpr unsigned windowPositionX = 150;
constexpr unsigned windowPositionY = 50;

FlappyBird* FlappyBird::instance = nullptr;  // NOLINT false positive

FlappyBird::FlappyBird() : viewId(1), model(nullptr) {
  // Initialize SDL2 with video and audio
  // TODO: handle error
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    ;
  }
  // Use OpenGL 2.1
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

  this->initWindowForSdl();
  this->setViewId(1);
}

FlappyBird::~FlappyBird() {
  if (gWindow != nullptr) {
    SDL_DestroyWindow(gWindow);  // Destroy window
  }
  gWindow = nullptr;

  SDL_Quit();  // Quit SDL subsystems
}

void FlappyBird::setViewId(unsigned viewId) {
  unsigned score;
  GamePageModel* gamePageModel = nullptr;
  if (this->viewId == 3) {
    gamePageModel = dynamic_cast<GamePageModel*>(model);
    score = gamePageModel->getScoreBoard().getScore();
  }
  delete controller;
  delete view;
  delete model;

  switch (viewId) {
    case 1:
      if (this->viewId == 3 or this->viewId == 4) {
        this->initWindowForSdl();
      }
      this->model = new StartPageModel();
      this->view = new StartPageView(gWindow, gScreenSurface,
                                     dynamic_cast<StartPageModel*>(model));
      this->controller =
          new StartPageController(dynamic_cast<StartPageView*>(view),
                                  dynamic_cast<StartPageModel*>(model));
      break;
    case 2:
      if (this->viewId == 3 or this->viewId == 4) {
        this->initWindowForSdl();
      }
      this->model = new OptionsPageModel();
      this->view = new OptionsPageView(gWindow, gScreenSurface,
                                       dynamic_cast<OptionsPageModel*>(model));
      this->controller =
          new OptionsPageController(dynamic_cast<OptionsPageView*>(view),
                                    dynamic_cast<OptionsPageModel*>(model));
      break;
    case 3: {
      if (this->viewId == 1 or this->viewId == 2) {
        this->initWindowForOpenGl();
      }
      ComponentFactory factory;
      this->model = new GamePageModel(&factory);
      this->view = new GamePageView(dynamic_cast<GamePageModel*>(model));
      this->controller =
          new GamePageController(dynamic_cast<GamePageView*>(view),
                                 dynamic_cast<GamePageModel*>(model));
    } break;
    case 4:
      this->model = nullptr;
      this->view = new ResultPageView(score);
      this->controller = nullptr;
      break;
  }
  this->viewId = viewId;
}

void FlappyBird::render() {
  this->view->render();
  if (this->viewId == 3 or this->viewId == 4) {
    SDL_GL_SwapWindow(this->gWindow);
  }
}

void FlappyBird::run() {
  this->render();

  SDL_Event e;  // Event handler

  // While application is running
  while (true) {
    if (this->viewId == 3) {
      dynamic_cast<GamePageController*>(controller)->idleStateHandler();
      this->render();

      if (dynamic_cast<GamePageModel*>(model)->isGameOver()) {
        this->onGameOver();
        this->setViewId(4);
        this->render();
        sleep(1);
        this->setViewId(1);
        this->render();
      }
    }
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

bool FlappyBird::handleEvent(const SDL_Event& e) {
  if (e.type == SDL_QUIT) {
    musicPlayer.stop();
    return false;
  }
  if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {
      case SDLK_RETURN:
        if (viewId == 1) {
          switch (dynamic_cast<StartPageModel*>(model)->getCursorPosition()) {
            case 1:
              this->setViewId(3);
              break;
            case 2:
              this->setViewId(2);
              break;
            case 0:
              musicPlayer.stop();
              return false;
          }
        }
        break;
      case SDLK_ESCAPE:
        if (viewId == 2) {
          this->setViewId(1);
        }
        break;
    }
    this->render();
  }
  return true;
}

void FlappyBird::onGameOver() {
  std::ifstream score_File("../res/scores.data", std::ios::in);

  unsigned numScores = 0;
  score_File >> numScores;

  std::vector<unsigned> highScores(numScores);
  for (int i = 0; i < numScores; i++) {
    score_File >> highScores[i];
  }

  score_File.close();

  highScores.push_back(
      dynamic_cast<GamePageModel*>(model)->getScoreBoard().getScore());
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

FlappyBird* FlappyBird::getInstance() {
  if (instance == nullptr) {
    instance = new FlappyBird;  // NOLINT
  }
  return instance;
}

bool FlappyBird::initWindowForOpenGl() {
  // Initialization flag
  bool success = true;

  success = this->createWindow();

  // Create context
  SDL_GLContext gContext;
  gContext = SDL_GL_CreateContext(gWindow);
  if (gContext == NULL) {
    success = false;
  } else {
    // Do not use Vsync
    if (SDL_GL_SetSwapInterval(0) < 0) {
      success = false;
    }

    // Initialize OpenGL
    success = this->initOpenGl();
  }

  return success;
}

bool FlappyBird::initWindowForSdl() {
  // Initialization flag
  bool success = true;

  success = this->createWindow();

  this->gScreenSurface = SDL_GetWindowSurface(gWindow);  // Get window surface

  return success;
}

bool FlappyBird::createWindow() {
  // Create window
  if (gWindow != NULL) {
    SDL_DestroyWindow(gWindow);
  }
  this->gWindow = SDL_CreateWindow(
      "FLAPPY BIRDS", windowPositionX, windowPositionY, screenResolutionX,
      screenResolutionY, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (gWindow == NULL) {
    return false;
  }
}

bool FlappyBird::initOpenGl() {
  bool success = true;
  GLenum error = GL_NO_ERROR;

  // Initialize Projection Matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Check for error
  /*error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    success = false;
  }*/

  // Initialize Modelview Matrix
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Check for error
  /*error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    success = false;
  }*/

  // Initialize clear color
  glClearColor(0.f, 0.f, 0.f, 1.f);

  // Check for error
  /*error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    success = false;
  }*/

  return success;
}
