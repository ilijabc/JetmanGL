/*
 * TestClient.cpp
 *
 *  Created on: 22.10.2012.
 *      Author: idjukic
 */

#include "TestClient.h"
#include <GL/glfw.h>

GameClient *GameClient::Initialize(GameClientSettings settings)
{
	return new TestClient(settings);
}

TestClient::TestClient(GameClientSettings settings)
{
	mView = new GLView();
	mView->setup();
	mView->setSize(settings.width, settings.height);
	mFont = new GLFont("Data/Arial.fnt");
	mScene = new GameScene(this);
	if (settings.cmdline)
		mScene->loadSVG(settings.cmdline);
	else
		printf("NO SVG LEVEL!\n");
	mSceneSize.set(settings.width, settings.height);
	for (int i = 0; i < 8; i++)
		mButtonState[i] = GLFW_RELEASE;
	mCameraPos.set(0, 0, 100);
	//gui
	mTestForm = new GUIForm(0, 0, 200, 300);
	mTestForm->setFont(mFont);
	mTestForm->setEventListener(this);
	GUIButton *button1 = mTestForm->addControl<GUIButton>(50, 50, 100, 30, "Button 1");
	GUIButton *button2 = mTestForm->addControl<GUIButton>(50, 100, 100, 30, "Button 2");
	GUIButton *button3 = mTestForm->addControl<GUIButton>(50, 150, 100, 30, "Button 3");
}

TestClient::~TestClient()
{
	delete mTestForm;
	delete mScene;
	delete mView;
}

void TestClient::onUpdate(float dt)
{
	mScene->update(dt);
	mTestForm->doEvents();
}

void TestClient::onDraw()
{
	mSceneSize = mView->beginScene2DWide(mCameraPos.z);
	glPushMatrix();
	//grid
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(-mSceneSize.x / 2, mCameraPos.y);
	glVertex2f(mSceneSize.x / 2, mCameraPos.y);
	glVertex2f(mCameraPos.x, -mSceneSize.y / 2);
	glVertex2f(mCameraPos.x, mSceneSize.y / 2);
	glEnd();
	//scene
	glTranslatef(mCameraPos.x, mCameraPos.y, 0);
	mScene->draw(mView);
	glPopMatrix();
	mView->endScene2D();
	//gui
	mView->beginGui(800, 600);
	mTestForm->draw(mView);
	mView->endGui();
}

void TestClient::onKeyEvent(int key, int action)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_SPACE)
		{
			//toggle drawing flags
			if ((mScene->getDrawFlags() & GameScene::e_drawBox2DFlag) == GameScene::e_drawBox2DFlag)
				mScene->setDrawFlags(GameScene::e_drawShapeFlag | GameScene::e_drawImageFlag);
			else
				mScene->setDrawFlags(GameScene::e_drawBox2DFlag | GameScene::e_drawBoundsFlag);
		}
		if (mTestForm)
		{
			mTestForm->sendKeyPress(key);
		}
	}
}

void TestClient::onMouseMoveEvent(int x, int y)
{
	float dx = x - mMousePos.x;
	float dy = y - mMousePos.y;
	if (mButtonState[GLFW_MOUSE_BUTTON_RIGHT] == GLFW_PRESS)
	{
		float fx = mSceneSize.x / (float)mView->getWidth();
		float fy = mSceneSize.y / (float)mView->getHeight();
		mCameraPos.x += dx * fx;
		mCameraPos.y -= dy * fy;
	}
	mMousePos.x = x;
	mMousePos.y = y;
	if (mTestForm)
	{
		mTestForm->sendMouseMove(x, y);
	}
}

void TestClient::onMouseButtonEvent(int button, int press)
{
	bool gui_event = false;
	if (mTestForm)
	{
		if (press == GLFW_PRESS)
			gui_event = mTestForm->sendButtonDown();
		else
			mTestForm->sendButtonUp();
	}
	if (!gui_event)
		mButtonState[button] = press;
}

void TestClient::onMouseWheelEvent(int wheel)
{
	float dz = wheel - mMousePos.z;
	mCameraPos.z -= dz * 5;
	if (mCameraPos.z < 5)
		mCameraPos.z = 5;
	mMousePos.z = wheel;
}

void TestClient::onSize(int width, int height)
{
	mView->setSize(width, height);
}

void TestClient::onEvent(GUIEvent *e)
{
	if (e->type == GUIEvent::e_clickEvent)
	{
		e->control->setText("clicked!");
	}
}
