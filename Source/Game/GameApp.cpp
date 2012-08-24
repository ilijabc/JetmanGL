/*
 * GameApp.cpp
 *
 *  Created on: Jun 13, 2012
 *      Author: Ilija
 */

#include "GameApp.h"
#include <GL/glfw.h>
#include <string.h>


GameApp::GameApp(int width, int height)
{
	GLParticleSystemProperties PSP_Boom;
	PSP_Boom.Size.setValue(1, 2);
	PSP_Boom.MoveSpeed.setValue(10, 20);

	GLParticleSystemProperties PSP_Fire;
	PSP_Fire.AngleWidth = 30;
	PSP_Fire.Size.setValue(0.1, 0.3);
	//PSP_Fire.SpawnRadius = 0.3;
	PSP_Fire.Color.set(1, 0.8, 0);
	PSP_Fire.LifeTime.setValue(1, 0.2);

    mouse.x = 0;
    mouse.y = 0;
    mouse.wheel = 0;
    mouse.button[0] = 0;
    mouse.button[1] = 0;
    mouse.button[2] = 0;
    mouse.button[3] = 0;
    memset(keyState, 0, (GLFW_KEY_LAST + 1) * sizeof(int));
    camera.set(0, 0, 200);

    view = new GLView();
	view->setup();
    view->setSize(width, height);

	tex = new GLTexture("Data/spot.png");
	font = new GLFont("Data/Arial.fnt");
	boom = new GLParticleSystem();
	boom->Properties = PSP_Fire;
	boom->setTexture(tex);
	boom->rotation = 90;
	strcpy(text, "...");

	level = new GameLevel();
	mPlayer = level->createPlayer(10, 10);
	mLockOnPlayer = true;
}


GameApp::~GameApp()
{
	delete tex;
	delete font;
	delete boom;
	delete level;
}


void GameApp::onUpdate(float dt)
{
	boom->update(dt);
	sprintf(text, "#%d", boom->getParticlesCount());

	level->update(dt);
	if (mLockOnPlayer)
	{
		camera.x = mPlayer->getBody()->GetPosition().x;
		camera.y = mPlayer->getBody()->GetPosition().y;
	}
}


void GameApp::onDraw()
{
	sceneSize = view->beginScene2DWide(camera.z / 10);
	glTranslatef(-camera.x, -camera.y, 0);
	boom->draw();
	level->draw(view);
	view->endScene2D();

	view->beginGui();
	font->beginText(0, 0, 300, 50);
	font->drawText("JetmanGL git version", 0);
	font->endText();
	view->endGui();
}


void GameApp::onKeyEvent(int key, int action)
{
	if (action == GLFW_PRESS)
	{
		if (key == 'X')
		{
			boom->explode(100);
		}
		else if (key == 'C')
		{
			boom->startEmitter(0.02);
		}
		else if (key == 'V')
		{
			boom->stopEmitter();
		}
	}

	//state
	keyState[key] = action;
}


void GameApp::onMouseMoveEvent(int x, int y)
{
	int dx = x - mouse.x;
	int dy = y - mouse.y;

	mouse.sx = sceneSize.x / view->getWidth() * x - sceneSize.x / 2 + camera.x;
	mouse.sy = sceneSize.y / 2 - sceneSize.y / view->getHeight() * y + camera.y;

	if (mLockOnPlayer)
	{
		if (mouse.button[0])
		{
			b2Vec2 mv(mouse.sx, mouse.sy);
			mPlayer->getBody()->ApplyForceToCenter(mPlayer->getBody()->GetPosition() - mv);
		}
	}
	else
	{
		if (mouse.button[0])
		{
			camera.x -= dx * 0.1;
			camera.y += dy * 0.1;
		}
	}

	boom->position.x = mouse.sx;
	boom->position.y = mouse.sy;

	//state
	mouse.x = x;
	mouse.y = y;
}


void GameApp::onMouseButtonEvent(int button, int press)
{
	if (button == 0)
	{
		if (press)
		{
			boom->startEmitter(0.02);
		}
		else
		{
			boom->stopEmitter();
		}
	}
	else if (button == 1 && press)
	{
		GamePlayer *player = level->createPlayer(mouse.sx, mouse.sy);
	}

	//state
	mouse.button[button] = press;
}


void GameApp::onMouseWheelEvent(int wheel)
{
	int dwheel = wheel - mouse.wheel;

	camera.z -= dwheel * 10;

	//state
	mouse.wheel = wheel;
}


void GameApp::onSize(int width, int height)
{
    view->setSize(width, height);
}
