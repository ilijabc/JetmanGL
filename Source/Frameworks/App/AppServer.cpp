/*
 * AppServer.cpp
 *
 *  Created on: 29.01.2013.
 *      Author: idjukic
 */

#include "AppServer.h"
#include <GL/glfw.h>

#ifdef __cplusplus
extern "C" {
#include "iniParser/iniparser.h"
}
#endif

static AppClient *g_app_client = NULL;

static void cb_key(int key, int press)
{
    if (g_app_client)
    {
        g_app_client->onKeyEvent(key, press);
    }
    if (key == GLFW_KEY_ESC)
    {
        glfwCloseWindow();
    }
}

static void cb_mouse_pos(int x, int y)
{
    if (g_app_client)
    {
        g_app_client->onMouseMoveEvent(x, y);
    }
}

static void cb_mouse_button(int button, int press)
{
    if (g_app_client)
    {
        g_app_client->onMouseButtonEvent(button, press);
    }
}

static void cb_mouse_wheel(int wheel)
{
    if (g_app_client)
    {
        g_app_client->onMouseWheelEvent(wheel);
    }
}

static void cb_size(int width, int height)
{
    if (g_app_client)
    {
        g_app_client->onSize(width, height);
    }
}

AppServer::AppServer(const char *settings_path)
{
	mClient = NULL;
	mInitialized = false;
	mRunning = false;

    if (!glfwInit())
    {
        LOG("init fail");
        return;
    }

    dictionary *ini = iniparser_load(settings_path);
    mSettings.width = iniparser_getint(ini, "video:width", 640);
    mSettings.height = iniparser_getint(ini, "video:height", 480);
    mSettings.fullscreen = iniparser_getint(ini, "video:fullscreen", 0);
    mSettings.desktop = iniparser_getint(ini, "video:desktop", 0);
	mSettings.audio = iniparser_getint(ini, "audio:enabled", 0);
    iniparser_freedict(ini);
#ifdef DEBUG
    mSettings.width = 800;
    mSettings.height = 600;
    mSettings.fullscreen = 0;
    mSettings.desktop = 0;
#else
    if (mSettings.desktop)
    {
        GLFWvidmode dm;
        glfwGetDesktopMode(&dm);
        mSettings.width = dm.Width;
        mSettings.height = dm.Height;
        mSettings.fullscreen = 1;
    }
#endif

    //glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if (!glfwOpenWindow(
    		mSettings.width,
    		mSettings.height,
    		8, 8, 8, 8,
    		16,
    		0,
    		mSettings.fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW))
    {
        LOG("failed opening window");
        glfwTerminate();
        return;
    }
    glfwSwapInterval(0);
    glfwSetWindowTitle("GLFW Application + GLPlus");
    glfwSetKeyCallback(cb_key);
    glfwSetMousePosCallback(cb_mouse_pos);
    glfwSetMouseButtonCallback(cb_mouse_button);
    glfwSetMouseWheelCallback(cb_mouse_wheel);
    glfwSetWindowSizeCallback(cb_size);
    if (mSettings.fullscreen)
        glfwEnable(GLFW_MOUSE_CURSOR);

    mInitialized = true;
}

AppServer::~AppServer()
{
	glfwTerminate();
	g_app_client = NULL;
}

int AppServer::run(AppClient *client)
{
	mClient = client;
	g_app_client = client;

    float ftime = glfwGetTime();

    while (glfwGetWindowParam(GLFW_OPENED))
    {
        //
        //update
        //
        float dt = glfwGetTime() - ftime;
        mClient->onUpdate(dt);
        ftime = glfwGetTime();

        //
        //draw
        //
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        mClient->onDraw();
        glfwSwapBuffers();
    }

    return 0;
}
