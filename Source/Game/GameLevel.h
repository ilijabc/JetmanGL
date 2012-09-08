/*
 * JetmanLevel.h
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#ifndef JETMANLEVEL_H_
#define JETMANLEVEL_H_

#include "GameCommon.h"
#include "GameObject.h"

class GameLevel : public b2ContactListener
{
public:
	GameLevel(const char *level_svg);
	virtual ~GameLevel();
	virtual void BeginContact(b2Contact* contact);
	void update(float dt);
	void draw(GLView *view);
    inline b2World *getWorld() const { return mWorld; }
    //factory
    GameObject *createObject(float x, float y, float w, float h, GameObject::Type type);
    void destroyObject(GameObject *obj);
    inline GameObject *getPlayer() const { return mPlayer; }
    GLTexture *getTexture(const char *filename);
    inline const Rect& getBounds() const { return mBounds; }
    inline b2Body *getGround() const { return mGround; }
    inline void setFont(GLFont *font) { mFont = font; }
    GLFont *getFont() const { return mFont; }
    inline int getBoxes() const { return mBoxCounter; }

private:
	void drawBodyDebug(b2Body *body);
    void loadSVGLevel(const char *filename);
    void loadSVGLevel_XML(const char *filename);

private:
	b2World *mWorld;
	float mWorldUpdateTimeout;
	std::list<GameObject*> mGameObjectList;
	GameObject *mPlayer;
	std::vector<GLTexture*> mTexturePool;
	Rect mBounds;
	b2Body *mGround;
	GLParticleSystem mBoom;
	GLFont *mFont;
	int mBoxCounter;
};

#endif /* JETMANLEVEL_H_ */
