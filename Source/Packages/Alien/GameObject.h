#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameCommon.h"

class GameObject
{
public:
	enum Type
	{
		UNKNOWN = 0,
		BOX,
		CRAFT,
		ALIEN,
		PLATFORM,
		RECT
	};

private:
	void init();

public:
	GameObject();
	GameObject(GameLevel *level, float x, float y, float w, float h, Type type);
	GameObject(GameLevel *level, b2Vec2 *plist, int plist_size);
	virtual ~GameObject();
	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);
	inline b2Body *getBody() const { return mBody; }
	inline void setTexture(GLTexture *tex) { mTexture = tex; }
	inline GLTexture *getTexture() const { return mTexture; }
    inline Type getType() const { return mType; }
    void releaseBox();

private:
    GameLevel *mScene;
	b2Body *mBody;
    GLTexture *mTexture;
    Rect mBounds;
    Type mType;
    b2Joint *mJoint;
    int mEvent;
    GameObject *mEventObject;
    char *mMessage;
	b2Vec2 *mEdgeList;
	Triangle *mTriangleList;

public:
	struct
	{
		bool hasLine;
		bool hasFill;
		float lineColor[4];
		float lineWidth;
		float fillColor[4];
	} mPathStyle;
};

#endif // GAMEOBJECT_H
