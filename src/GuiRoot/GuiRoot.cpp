#include "GuiRoot.h"

GuiRoot::GuiRoot() {
  this->gWindow =
      SDL_CreateWindow("FLAPPY BIRDS", 150, 50, 640, 480, SDL_WINDOW_SHOWN);
  if (gWindow == NULL) {
    // handle error
  }
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

void GuiRoot::render() { this->view->render(); }

/*void GuiRoot::setView(View *view) {
  this->view = view;
}*/

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
          // goto QUIT;
          stop_Music();
          SDL_DestroyWindow(gWindow);  // Destroy window
          gWindow = NULL;
          SDL_Quit();  // Quit SDL subsystems
          exit(0);     // EXIT
        } else if (e.type == SDL_KEYDOWN) {
          switch (e.key.keysym.sym) {
            case SDLK_RETURN:
              if (!opt_Page) {
                switch (startPageModel->getCursorPosition()) {
                  case 1:
                    // goto EXIT_SDL;
                    SDL_DestroyWindow(gWindow);  // Destroy window
                    gWindow = NULL;
                    return;
                  case 2:
                    opt_Page = true;
                    view = optionsPageView;
                    controller = optionsPageController;
                    view->render();
                    break;
                  case 0:
                    // goto QUIT;
                    stop_Music();
                    SDL_DestroyWindow(gWindow);  // Destroy window
                    gWindow = NULL;
                    SDL_Quit();  // Quit SDL subsystems
                    exit(0);     // EXIT
                    break;
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
