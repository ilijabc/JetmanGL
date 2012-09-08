/*
 * GameApp.h
 *
 *  Created on: Jun 13, 2012
 *      Author: Ilija
 */

#ifndef GAMEAPP_H_
#define GAMEAPP_H_

#include "GameCommon.h"
#include "GameLevel.h"
#include <GL/glfw.h>

class GameApp
{
public:
	GameApp(int width, int height);
	virtual ~GameApp();
	void onUpdate(float dt);
	void onDraw();
	void onKeyEvent(int key, int action);
	void onMouseMoveEvent(int x, int y);
	void onMouseButtonEvent(int button, int press);
	void onMouseWheelEvent(int wheel);
    void onSize(int width, int height);

private:
	struct
	{
		int x;
		int y;
		int wheel;
		int button[4];
		float sx;
		float sy;
	} mouse;
	int keyState[GLFW_KEY_LAST + 1];
	GLView      *view;
	GLFloat3	camera;
	GLFloat2	sceneSize;
	GLTexture *mTexturePool[10];
	GLFont 		*font;
	GLParticleSystem *boom;
	char 		text[200];
	GameLevel	*level;
	GameObject* mPlayer;
	bool mLockOnPlayer;
	float mTime;
	bool mTimer;
	float mFadeOut;
};

#endif /* GAMEAPP_H_ */
