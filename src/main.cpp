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




SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *option_Page_Text = NULL;
SDL_Surface *gStartPage = NULL;
SDL_Surface *options_Page = NULL;




float position_of_bird;
int option=2, opt_option=111;
bool opt_Page;






void Init()
{
/*
Initialise or reinitialise the game, resetting
the variables and swapping to start page
*/
position_of_bird=0;

obstacle_1_vertex[0][0]=1.2;
obstacle_1_vertex[0][1]=1.0;
obstacle_1_vertex[1][0]=1.0;
obstacle_1_vertex[1][1]=1.0;
obstacle_1_vertex[2][0]=1.0;
obstacle_1_vertex[2][1]=0.0;
obstacle_1_vertex[3][0]=1.2;
obstacle_1_vertex[3][1]=0.0;

obstacle_2_vertex[0][0]=2.3;
obstacle_2_vertex[0][1]=-1.0;
obstacle_2_vertex[1][0]=2.1;
obstacle_2_vertex[1][1]=-1.0;
obstacle_2_vertex[2][0]=2.1;
obstacle_2_vertex[2][1]=0.0;
obstacle_2_vertex[3][0]=2.3;
obstacle_2_vertex[3][1]=0.0;

Brain.reset();

if (!CSRP_SDL2::SDL2_Engine_init())
    abort();

gWindow = SDL_CreateWindow( "FLAPPY BIRDS", 150, 50, 640, 480, SDL_WINDOW_SHOWN );
if( gWindow != NULL )
{
    gScreenSurface = SDL_GetWindowSurface( gWindow );   //Get window surface
}

LOAD_START_PAGE:
if (option==2)
    gStartPage = SDL_LoadBMP( "../res/Start_Page_2.bmp" );
else if (option==3)
    gStartPage = SDL_LoadBMP( "../res/Start_Page_3.bmp" );
else if (option==1)
    gStartPage = SDL_LoadBMP( "../res/Start_Page_1.bmp" );

if (opt_option==121 or opt_option==221 or opt_option==222 or opt_option==122)
{
    if (Mix_PlayingMusic() != 1)
        play_Music("../res/01.mp3");
}
else
{
    stop_Music();
}

SDL_BlitSurface( gStartPage, NULL, gScreenSurface, NULL );      //Apply the image
SDL_UpdateWindowSurface( gWindow );                             //Update the surface
goto INPUT_HANDLER;

OPTIONS:
if (opt_option==111)
    options_Page = SDL_LoadBMP( "../res/Options_M0_S0_MP.bmp" );
else if (opt_option==112)
    options_Page = SDL_LoadBMP( "../res/Options_M0_S1_MP.bmp" );
else if (opt_option==121)
    options_Page = SDL_LoadBMP( "../res/Options_M1_S0_MP.bmp" );
else if (opt_option==122)
    options_Page = SDL_LoadBMP( "../res/Options_M1_S1_MP.bmp" );
else if (opt_option==211)
    options_Page = SDL_LoadBMP( "../res/Options_M0_S0_SP.bmp" );
else if (opt_option==212)
    options_Page = SDL_LoadBMP( "../res/Options_M0_S1_SP.bmp" );
else if (opt_option==221)
    options_Page = SDL_LoadBMP( "../res/Options_M1_S0_SP.bmp" );
else if (opt_option==222)
    options_Page = SDL_LoadBMP( "../res/Options_M1_S1_SP.bmp" );
SDL_BlitSurface( options_Page, NULL, gScreenSurface, NULL );     //Apply the image
SDL_UpdateWindowSurface( gWindow );                 		     //Update the surface
opt_Page=true;
goto INPUT_HANDLER;

INPUT_HANDLER:
SDL_Event e;            //Event handler

//While application is running
while( true )
{
//Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_QUIT )    //User requests quit
            goto QUIT;
        else if( e.type == SDL_KEYDOWN )    //User presses a key
        {
        switch( e.key.keysym.sym )
        {
        case SDLK_DOWN:
            if (!opt_Page and option>0 and option<3)
                option++;
            else if (opt_Page and opt_option>100 and opt_option<150)
                opt_option+=100;
            break;

        case SDLK_UP:
            if (!opt_Page and option>1 and option<4)
                option--;
            else if (opt_Page and opt_option>200 and opt_option<250)
                opt_option-=100;
            break;

        case SDLK_RETURN:
            if (!opt_Page)
            {
                switch (option)
                {
                case 1:
                    goto EXIT_SDL;
                case 2:
                    goto OPTIONS;
                    break;

                case 3:
                    goto QUIT;
                default:
                    break;
                }
                break;
            }
            else
            {
                switch (opt_option)
                {
                case 111:
                    opt_option=121;
                    break;
                case 112:
                    opt_option=122;
                    break;
                case 121:
                    opt_option=111;
                    break;
                case 122:
                    opt_option=112;
                    break;
                case 211:
                    opt_option=212;
                    break;
                case 212:
                    opt_option=211;
                    break;
                case 221:
                    opt_option=222;
                    break;
                case 222:
                    opt_option=221;
                    break;
                default:
                    break;
                }
            }
            break;

        case SDLK_ESCAPE:
            if (opt_Page)
                opt_Page=false;
            break;

        default:
            break;
        }
        }
        if (opt_Page)
            goto OPTIONS;
        else
            goto LOAD_START_PAGE;
    }
}

QUIT:
stop_Music();
SDL_FreeSurface( gStartPage );                                  //Deallocate surface
gStartPage = NULL;
SDL_DestroyWindow( gWindow );                                   //Destroy window
gWindow = NULL;
SDL_Quit();                                                     //Quit SDL subsystems
exit(0);                                                        //EXIT

EXIT_SDL:
SDL_FreeSurface( gStartPage );                                  //Deallocate surface
gStartPage = NULL;
SDL_DestroyWindow( gWindow );                                   //Destroy window
gWindow = NULL;
}




void Obstacle()
{
/*
Function to draw an obstacle
*/
if (obstacle_1_vertex[0][0]<-1.0)
    Brain.create_Obstacle(1);

if (obstacle_2_vertex[0][0]<-1.0)
    Brain.create_Obstacle(2);

float x[4],y[4];

for(int i=0; i<4; i++)  {
    x[i]=obstacle_1_vertex[i][0];
    y[i]=obstacle_1_vertex[i][1];
    }

Artist.draw_Obstacle(x,y);

for(int i=0; i<4; i++)  {
    x[i]=obstacle_2_vertex[i][0];
    y[i]=obstacle_2_vertex[i][1];
    }

Artist.draw_Obstacle(x,y);

}




void display()
{
/*
Call those functions that have to draw their
specifics, based on game states
*/
glClearColor(0.0, 0.0, 0.0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);

Artist.draw_Backgrounds();
Artist.draw_Bird(0, position_of_bird);
Obstacle();
Artist.display_Score(TOP_RIGHT, Brain.get_Score());

if (is_Game_Paused)
    pause_Game();

glutSwapBuffers();
}




void idle_State()
{
/*
Entire game's AI and graphics is handled here as
there is very little user interaction compared
with the rapidness of loops
*/
if(!Brain.check_if_lost(0 ,position_of_bird))
{
    Brain.calc_Velocity();

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if (is_Key_Pressed['w'])    {
        position_of_bird+=Brain.get_Velocity();

        for (int i=0; i<4; i++)
        {
            obstacle_1_vertex[i][0]-=Brain.get_Velocity();
            obstacle_2_vertex[i][0]-=Brain.get_Velocity();
        }
    }


    else {
        position_of_bird-=Brain.get_Velocity();

        for (int i=0; i<4; i++)
        {
            obstacle_1_vertex[i][0]-=Brain.get_Velocity();
            obstacle_2_vertex[i][0]-=Brain.get_Velocity();
        }
    }

    Brain.calc_Score();

    glutPostRedisplay();
}

if(Brain.check_if_lost(0, position_of_bird))
{
    ifstream score_File("../res/scores.data",ios::in);
    float high_Scores[12];
    for (int i=0;i<10;i++)
        score_File>>high_Scores[i];
    for (int i=0;i<10;i++)
    {
        if (Brain.get_Score()>high_Scores[i])
        {
        float temp[12];
        for (int j=i;j<10;j++)
            temp[j]=high_Scores[j];
        for (int j=i;j<10;j++)
            high_Scores[j+1]=temp[j];
        high_Scores[i]=Brain.get_Score();
        break;
        }
    }
    score_File.close();
    ofstream score_File_Out("../res/scores.data",ios::out);
    for (int i=0;i<10;i++)
        score_File_Out<<high_Scores[i]<<endl;
    score_File.close();

    game_End e;
    e.declare_Over(Brain.get_Score());
    glutHideWindow();
    Init();
    glutShowWindow();
}
}




static void resize(int width, int height)
{
/*
Handle what happens when OpenGL window is resized
*/
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




void keyPressed(unsigned char key, int x, int y)
{
/*
Nothing much to do, just change states, except for few
key strokes, which require action
*/
switch (key)
{
    case ESC:
    {
        if (is_Game_Paused)
            resume(idle_State);
        else
            pause_Game();

        break;
    }
    case SPACE:
    {
        if (is_Game_Paused)
            resume(idle_State);
        else
            pause_Game();

        break;
    }
    default:
        break;
}

for (int i=0; i<256; i++)
    if (key==i)
        is_Key_Pressed[i]=true;
}




void keyReleased(unsigned char key, int x, int y)
{
/*
Nothing much to do, just change states
*/
for (int i=0; i<256; i++)
    if (key==i)
        is_Key_Pressed[i]=false;
}



/*The ultimate function*/
int main(int argc, char *argv[])
{
//Initialize SDL2 and the vertices required for game play...
if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) >= 0 )            //Initialize SDL with video and audio
{
Init();             //Handle start page graphics...
}

//Transition to complete OPENGL to handle game play and related graphics

glutInit(&argc, argv);                  //Initialize glut with arguments passed
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);    //Set the display mode to single buffering and RGBA(Alpha) mode
glutReshapeFunc(resize);                //Function to scale and get diplay ratios according to new dimensions
glutInitWindowPosition(150,50);         //Set the window position
glutInitWindowSize(640,480);            //Set the window size, measured in pixels
glutCreateWindow("FLAPPY BIRDS");       //Set window title
glutDisplayFunc(display);               //Register a callback func. to handle what to display
glutKeyboardFunc(keyPressed);           //Register a callback func. to handle key-presses
glutKeyboardUpFunc(keyReleased);        //Register a callback func. to handle key-releases
glutIdleFunc(idle_State);               //Register a callback func. to handle idle situations(Nothing has happened during loop)
glutMainLoop();                         //Start main loop

return 0;
}
