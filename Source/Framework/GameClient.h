/*
 * GameClient.h
 *
 *  Created on: 19.10.2012.
 *      Author: idjukic
 */

#ifndef GAMECLIENT_H_
#define GAMECLIENT_H_

#include "GameCommon.h"

struct GameClientSettings
{
	int width;
	int height;
	int audio;
};

class GameClient
{
public:
	GameClient();
	virtual ~GameClient();
	//callbacks
	virtual void onUpdate(float dt) = 0;
	virtual void onDraw() = 0;
	virtual void onKeyEvent(int key, int action) = 0;
	virtual void onMouseMoveEvent(int x, int y) = 0;
	virtual void onMouseButtonEvent(int button, int press) = 0;
	virtual void onMouseWheelEvent(int wheel) = 0;
    virtual void onSize(int width, int height) = 0;
    //general
    static GameClient *Initialize(GameClientSettings settings);
};

#endif /* GAMECLIENT_H_ */
