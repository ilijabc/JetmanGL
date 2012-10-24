#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameCommon.h"

class GameScene;

class GameObject
{
public:
	struct Triangle { b2Vec2 a, b, c; };
	struct LineStyle { float color[4]; float width; };
	struct FillStyle { float color[4]; int type; };
	struct PolyLine {
		PolyLine(int size);
		~PolyLine();
		b2Vec2 *pointList; int pointCount; LineStyle style;
	};
	struct PolyFill {
		PolyFill(int size);
		~PolyFill();
		Triangle *triangleList; int triangleCount; FillStyle style;
	};

public:
	GameObject(GameScene *scene, int type);
	virtual ~GameObject();
	//events
	virtual void onUpdate(float dt);
	virtual void onDraw(GLView *view);
	virtual void onCollision(b2Body *other);
    //setters
	inline void setBody(b2Body *body) { mBody = body; }
	inline void setTexture(GLTexture *tex) { mTexture = tex; }
	inline void setTextureSize(float w, float h) { mTextureSize.Set(w / 2, h / 2); }
	inline void setPosition(const b2Vec2 &pos) { mPosition = pos; }
	inline void setPosition(float x, float y) { mPosition.Set(x, y); }
	//getters
	inline b2Body *getBody() const { return mBody; }
	inline GLTexture *getTexture() const { return mTexture; }
    inline int getType() const { return mType; }
    inline const b2Vec2 &getPosition() const { return mPosition; }
    //geomtry
    void addPolyLine(b2Vec2 *pointList, int pointCount, int color = 0xFFFFFFFF, float width = 1.0f);
    void addPolyFill(b2Vec2 *pointList, int pointCount, int color = 0xFFFFFFFF);
    void addRectFill(float x1, float y1, float x2, float y2, int color = 0xFFFFFFFF);

private:
    GameScene *mScene;
    int mType;
	b2Body *mBody;
    GLTexture *mTexture;
    b2Vec2 mTextureSize;
    std::list<PolyLine*> mLineList;
    std::list<PolyFill*> mFillList;
    b2Vec2 mPosition;
};

#endif // GAMEOBJECT_H
