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
	mScene = new GameScene(this);
	mScene->loadSVG("Data/level02.svg");
	mZoom = 100;
}

TestClient::~TestClient()
{
	delete mScene;
	delete mView;
}

void TestClient::onUpdate(float dt)
{
	mScene->update(dt);
}

void TestClient::onDraw()
{
	mView->beginScene2DWide(mZoom);
	mScene->draw(mView);
	mView->endScene2D();
}

void TestClient::onKeyEvent(int key, int action)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_SPACE)
		{
			//toggle drawing flags
			if (mScene->getDrawFlags() == GameScene::e_drawBox2DFlag)
				mScene->setDrawFlags(GameScene::e_drawShapeFlag | GameScene::e_drawImageFlag);
			else
				mScene->setDrawFlags(GameScene::e_drawBox2DFlag);
		}
	}
}

void TestClient::onMouseMoveEvent(int x, int y)
{
}

void TestClient::onMouseButtonEvent(int button, int press)
{
}

void TestClient::onMouseWheelEvent(int wheel)
{
	mZoom = 100 - wheel * 5;
}

void TestClient::onSize(int width, int height)
{
	mView->setSize(width, height);
}
