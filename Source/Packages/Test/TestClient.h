/*
 * TestClient.h
 *
 *  Created on: 22.10.2012.
 *      Author: idjukic
 */

#ifndef TESTCLIENT_H_
#define TESTCLIENT_H_

#include "Game/GameClient.h"
#include "Game/GameScene.h"
#include "GLPlus/GLUIDesktop.h"

class TestClient : public GameClient
{
public:
	TestClient(GameClientSettings settings);
	virtual ~TestClient();
	//callbacks
	virtual void onUpdate(float dt);
	virtual void onDraw();
	virtual void onKeyEvent(int key, int action);
	virtual void onMouseMoveEvent(int x, int y);
	virtual void onMouseButtonEvent(int button, int press);
	virtual void onMouseWheelEvent(int wheel);
    virtual void onSize(int width, int height);

private:
	GLView *mView;
	GLFont *mFont;
	GameScene *mScene;
	GLFloat2 mSceneSize;
	int mButtonState[8];
	GLFloat3 mMousePos;
	GLFloat3 mCameraPos;
	GLUIDesktop *mDesktop;
};

#endif /* TESTCLIENT_H_ */
