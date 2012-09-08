#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameCommon.h"

class GameObject
{
public:
	enum Type
	{
		BOX = 0,
		CRAFT,
		ALIEN
	};

public:
	GameObject(GameLevel *level, float x, float y, float w, float h, Type type);
	virtual ~GameObject();
	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);
	inline b2Body *getBody() const { return mBody; }
	inline void setTexture(GLTexture *tex) { mTexture = tex; }
	inline GLTexture *getTexture() const { return mTexture; }
    inline Type getType() const { return mType; }
    inline int getPoints() const { return mPoints; }
    void releaseBox();
    inline float getFule() const { return mFule; }
    inline void setFule(float v) { mFule = v; }
    inline void addFule(float v) { mFule += v; }

private:
    GameLevel *mLevel;
	b2Body *mBody;
    GLTexture *mTexture;
    Rect mBounds;
    Type mType;
    int mPoints;
    b2Joint *mJoint;
    int mEvent;
    GameObject *mEventObject;
    float mFule;
    char *mMessage;
};

#endif // GAMEOBJECT_H
