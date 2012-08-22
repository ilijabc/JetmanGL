/*
 * JetmanLevel.h
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#ifndef JETMANLEVEL_H_
#define JETMANLEVEL_H_

#include "GameCommon.h"
#include "GamePlayer.h"


class GameLevel
{
public:
	GameLevel();
	virtual ~GameLevel();

	void update(float dt);
	void draw(GLView *view);

	void addBox(float x, float y, bool is_player);

	template <class T> T* createObject(float x, float y);

private:
	void drawBodyDebug(b2Body *body);

private:
	b2World		*world;
	float		worldUpdateTimeout;
	std::list<GameObject*> gameObjectList;
};

//
//create implementation
//
template <class T>
T* GameLevel::createObject(float x, float y)
{
    //create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    b2Body* body = world->CreateBody(&bodyDef);
    //create object
    T* obj = new T(body);
    body->SetUserData(obj);
    gameObjectList.push_back(obj);
    return obj;
}

#endif /* JETMANLEVEL_H_ */
