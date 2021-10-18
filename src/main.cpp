/************************************************************
 *                                                           *
 *        _____   _       _____   _____   _____   _   _      *
 *       |  ___| | |     /  _  \ |  _  | |  _  | | | | |     *
 *       | |_    | |     | |_| | | |_| | | |_| | | |_| |     *
 *       |  _|   | |     |  _  | |  ___| |  ___| |____ |     *
 *       | |     | |___  | | | | | |     | |      ___| |     *
 *       |_|     |_____| |_| |_| |_|     |_|     |_____|     *
 *                                                           *
 *   _______   _______   ____     _____     ____             *
 *  |_   _  \ |__   __| |  _ \   |  _  \   |  __|            *
 *    | |_) /    | |    | |_) |  | | \  \  | |__             *
 *    |  _ (     | |    |  _ <   | |  |  | |__  |            *
 *   _| |_) \  __| |__  | | \ \  | |_/  /   __| |            *
 *  |_______/ |_______| |_|  \_\ |_____/   |____|            *
 *                                                           *
 *                                                           *
 *                                                           *
 *                        -by                                *
 *                                                           *
 *                                                           *
 *                 ______   ____     ____                    *
 *                /  ____) |  _ \   |  _ \                   *
 *          ____ (  (____  | |_) )  | |_) )                  *
 *         /  __) \____  \ |  _ <   |  __/                   *
 *        (  (__   ____)  )| | \ \  | |                      *
 *         \____) (______/ |_|  \_\ |_|                      *
 *                                                           *
 *                                                           *
 *************************************************************/

#include "CSRP_SDL2_engine.h"
#include "game_engine.h"

#include "StartPage/controller.h"
#include "StartPage/model.h"
#include "StartPage/view.h"

#include "OptionsPage/controller.h"
#include "OptionsPage/model.h"
#include "OptionsPage/view.h"

#include "GamePage/controller.h"
#include "GamePage/model.h"
#include "GamePage/view.h"

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *option_Page_Text = NULL;
SDL_Surface *gStartPage = NULL;
SDL_Surface *options_Page = NULL;

bool opt_Page;

GamePageModel gamePageModel;
GamePageView gamePageView(&gamePageModel);
GamePageController gamePageController(&gamePageView, &gamePageModel);

/*
class FlappyBirdView
{
public:
        void render();
        void drawObstacle();
}

class OptionPageModel
{
        bool soundOn;
        bool musicOn;

public:
  bool getSoundOn();
  bool getMusicOn();
}

class FlappyBirdModel
{
        Bird bird;
        Obstacle obstacle1, obstacle2;

public:
}

class FlappyBirdController
{
public:
        FlappyBirdController(FlappyBirdView*, FlappyBirdModel*);
}

class Bird
{
        float position;

public:
        void setPosition(float);
}

class Obstacle
{
        float height;

public:
        Obstacle(float);
}
*/

void Init() {
  /*
  Initialise or reinitialise the game, resetting
  the variables and swapping to start page
  */
  obstacle_1_vertex[0][0] = 1.2;
  obstacle_1_vertex[0][1] = 1.0;
  obstacle_1_vertex[1][0] = 1.0;
  obstacle_1_vertex[1][1] = 1.0;
  obstacle_1_vertex[2][0] = 1.0;
  obstacle_1_vertex[2][1] = 0.0;
  obstacle_1_vertex[3][0] = 1.2;
  obstacle_1_vertex[3][1] = 0.0;

  obstacle_2_vertex[0][0] = 2.3;
  obstacle_2_vertex[0][1] = -1.0;
  obstacle_2_vertex[1][0] = 2.1;
  obstacle_2_vertex[1][1] = -1.0;
  obstacle_2_vertex[2][0] = 2.1;
  obstacle_2_vertex[2][1] = 0.0;
  obstacle_2_vertex[3][0] = 2.3;
  obstacle_2_vertex[3][1] = 0.0;

  Brain.reset();

  if (!CSRP_SDL2::SDL2_Engine_init()) abort();

  gWindow =
      SDL_CreateWindow("FLAPPY BIRDS", 150, 50, 640, 480, SDL_WINDOW_SHOWN);
  if (gWindow != NULL) {
    gScreenSurface = SDL_GetWindowSurface(gWindow);  // Get window surface
  }

  StartPageModel startPageModel;
  StartPageView startPageView(gWindow, gScreenSurface, gStartPage,
                              &startPageModel);
  StartPageController startPageController(&startPageView, &startPageModel);

  OptionsPageModel optionsPageModel;
  OptionsPageView optionsPageView(gWindow, gScreenSurface, options_Page,
                                  &optionsPageModel);
  OptionsPageController optionsPageController(&optionsPageView,
                                              &optionsPageModel);

  View *view;
  Model *model;
  Controller *controller;

  // LOAD_START_PAGE:
  view = &startPageView;
  controller = &startPageController;

  view->render();

  if (optionsPageModel.isMusicOn()) {
    if (Mix_PlayingMusic() != 1) play_Music("../res/01.mp3");
  } else {
    stop_Music();
  }

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
                    SDL_FreeSurface(gStartPage);  // Deallocate surface
                    gStartPage = NULL;
                    SDL_DestroyWindow(gWindow);  // Destroy window
                    gWindow = NULL;
                    SDL_Quit();  // Quit SDL subsystems
                    exit(0);     // EXIT
        } else if (e.type == SDL_KEYDOWN) {
          switch (e.key.keysym.sym) {
            case SDLK_RETURN:
              if (!opt_Page) {
                switch (startPageModel.getCursorPosition()) {
                  case 1:
                    // goto EXIT_SDL;
                    SDL_FreeSurface(gStartPage);  // Deallocate surface
                    gStartPage = NULL;
                    SDL_DestroyWindow(gWindow);  // Destroy window
                    gWindow = NULL;
		    return;
                  case 2:
                    opt_Page = true;
                    view = &optionsPageView;
                    controller = &optionsPageController;
		    view->render();
                    break;
                  case 0:
                    // goto QUIT;
                    stop_Music();
                    SDL_FreeSurface(gStartPage);  // Deallocate surface
                    gStartPage = NULL;
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
                view = &startPageView;
                controller = &startPageController;

                view->render();
              }
              break;
          }
        }
      }
    }
  }
}

void display() { gamePageView.render(); }

void idle_State() {
  /*
  Entire game's AI and graphics is handled here as
  there is very little user interaction compared
  with the rapidness of loops
  */
  if (is_Game_Paused) {
    return;
  }

  if (!Brain.check_if_lost(0, gamePageModel.getPositionOfBird())) {
    Brain.calc_Velocity();

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (is_Key_Pressed['w']) {
      gamePageModel.setPositionOfBird(gamePageModel.getPositionOfBird() +
                                      Brain.get_Velocity());

      for (int i = 0; i < 4; i++) {
        obstacle_1_vertex[i][0] -= Brain.get_Velocity();
        obstacle_2_vertex[i][0] -= Brain.get_Velocity();
      }
    }

    else {
      gamePageModel.setPositionOfBird(gamePageModel.getPositionOfBird() -
                                      Brain.get_Velocity());

      for (int i = 0; i < 4; i++) {
        obstacle_1_vertex[i][0] -= Brain.get_Velocity();
        obstacle_2_vertex[i][0] -= Brain.get_Velocity();
      }
    }

    Brain.calc_Score();

    glutPostRedisplay();
  }

  if (Brain.check_if_lost(0, gamePageModel.getPositionOfBird())) {
    ifstream score_File("../res/scores.data", ios::in);
    float high_Scores[12];
    for (int i = 0; i < 10; i++) score_File >> high_Scores[i];
    for (int i = 0; i < 10; i++) {
      if (Brain.get_Score() > high_Scores[i]) {
        float temp[12];
        for (int j = i; j < 10; j++) temp[j] = high_Scores[j];
        for (int j = i; j < 10; j++) high_Scores[j + 1] = temp[j];
        high_Scores[i] = Brain.get_Score();
        break;
      }
    }
    score_File.close();
    ofstream score_File_Out("../res/scores.data", ios::out);
    for (int i = 0; i < 10; i++) score_File_Out << high_Scores[i] << endl;
    score_File.close();

    game_End e;
    e.declare_Over(Brain.get_Score());
    glutHideWindow();
    Init();
    glutShowWindow();
  }
}

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

void keyPressed(unsigned char key, int x, int y) {
  /*
  Nothing much to do, just change states, except for few
  key strokes, which require action
  */
  gamePageController.handleEvent(key, x, y);
}

void keyReleased(unsigned char key, int x, int y) {
  /*
  Nothing much to do, just change states
  */
  for (int i = 0; i < 256; i++)
    if (key == i) is_Key_Pressed[i] = false;
}

/*The ultimate function*/
int main(int argc, char *argv[]) {
  // Initialize SDL2 and the vertices required for game play...
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >=
      0)  // Initialize SDL with video and audio
  {
    Init();  // Handle start page graphics...
  }

  // Transition to complete OPENGL to handle game play and related graphics

  glutInit(&argc, argv);  // Initialize glut with arguments passed
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
  glutMainLoop();            // Start main loop

  return 0;
}
