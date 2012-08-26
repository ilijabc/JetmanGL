#include "GameApp.h"
#include <GL/glfw.h>

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
    int     width = 800;
    int     height = 600;
    float   ftime = 0;

    if (!glfwInit())
    {
        LOG("init fail");
        return 0;
    }

    //glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if (!glfwOpenWindow(width, height, 8, 8, 8, 8, 16, 0, GLFW_WINDOW))
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

    //
    //init
    //
    g_game = new GameApp(width, height);
    ftime = glfwGetTime();

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
