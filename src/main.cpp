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

#include "GuiRoot/GuiRoot.h"

GamePageModel gamePageModel;
GamePageView gamePageView(&gamePageModel);
GamePageController gamePageController(&gamePageView, &gamePageModel);

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

  /*if (optionsPageModel.isMusicOn()) {
    if (Mix_PlayingMusic() != 1) play_Music("../res/01.mp3");
  } else {
    stop_Music();
  }*/

  GuiRoot guiRoot;
  guiRoot.render();
  guiRoot.handleEvents();
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
  gamePageController.keyPressed(key, x, y);
}

void keyReleased(unsigned char key, int x, int y) {
  gamePageController.keyReleased(key, x, y);
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
