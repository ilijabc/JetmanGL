#include "GameApp.h"
#include <GL/glfw.h>

#ifdef __cplusplus
extern "C" {
#include "iniParser/iniparser.h"
}
#endif

GameApp *g_game = NULL;

static void cb_key(int key, int press)
{
    if (g_game)
    {
        g_game->onKeyEvent(key, press);
    }
    if (key == GLFW_KEY_ESC)
    {
        glfwCloseWindow();
    }
}

static void cb_mouse_pos(int x, int y)
{
    if (g_game)
    {
        g_game->onMouseMoveEvent(x, y);
    }
}

static void cb_mouse_button(int button, int press)
{
    if (g_game)
    {
        g_game->onMouseButtonEvent(button, press);
    }
}

static void cb_mouse_wheel(int wheel)
{
    if (g_game)
    {
        g_game->onMouseWheelEvent(wheel);
    }
}

static void cb_size(int width, int height)
{
    if (g_game)
    {
        g_game->onSize(width, height);
    }
}

int main(int argc, char *argv[])
{
    if (!glfwInit())
    {
        LOG("init fail");
        return 0;
    }

    dictionary *ini = iniparser_load("Data/settings.ini");
    int width = iniparser_getint(ini, "video:width", 640);
    int height = iniparser_getint(ini, "video:height", 480);
    int fullscreen = iniparser_getint(ini, "video:fullscreen", 0);
    int desktop = iniparser_getint(ini, "video:desktop", 0);
    iniparser_freedict(ini);
    if (desktop)
    {
        GLFWvidmode dm;
        glfwGetDesktopMode(&dm);
        width = dm.Width;
        height = dm.Height;
        fullscreen = 1;
    }
    //glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if (!glfwOpenWindow(width, height, 8, 8, 8, 8, 16, 0, fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW))
    {
        LOG("failed opening window");
        glfwTerminate();
        return 0;
    }
    glfwSwapInterval(0);
    glfwSetWindowTitle("GLFW Application + GLPlus");
    glfwSetKeyCallback(cb_key);
    glfwSetMousePosCallback(cb_mouse_pos);
    glfwSetMouseButtonCallback(cb_mouse_button);
    glfwSetMouseWheelCallback(cb_mouse_wheel);
    glfwSetWindowSizeCallback(cb_size);
    if (fullscreen)
        glfwEnable(GLFW_MOUSE_CURSOR);

    //
    //init
    //
    g_game = new GameApp(width, height);
    float ftime = glfwGetTime();

    while (glfwGetWindowParam(GLFW_OPENED))
    {
        //
        //update
        //
        float dt = glfwGetTime() - ftime;
        g_game->onUpdate(dt);
        ftime = glfwGetTime();

        //
        //draw
        //
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        g_game->onDraw();
        glfwSwapBuffers();
    }

    //finish
    delete g_game;

    glfwTerminate();

    return 0;
}
