/*
 * TestClient.cpp
 *
 *  Created on: 22.10.2012.
 *      Author: idjukic
 */

#include "TestClient.h"

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
	mView->beginScene2DWide(500);
	mScene->draw(mView);
	mView->endScene2D();
}

void TestClient::onKeyEvent(int key, int action)
{
}

void TestClient::onMouseMoveEvent(int x, int y)
{
}

void TestClient::onMouseButtonEvent(int button, int press)
{
}

void TestClient::onMouseWheelEvent(int wheel)
{
}

void TestClient::onSize(int width, int height)
{
	mView->setSize(width, height);
}
