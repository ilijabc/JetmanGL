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
	//getters
	inline b2Body *getBody() const { return mBody; }
	inline GLTexture *getTexture() const { return mTexture; }
    inline int getType() const { return mType; }
    //geomtry
    void addPolyLine(b2Vec2 *pointList, int pointCount, float color[4], float width = 1.0f);
    void addPolyFill(b2Vec2 *pointList, int pointCount, float color[4]);
    void addRectFill(float x1, float y1, float x2, float y2, float color[4]);

private:
    GameScene *mScene;
    int mType;
	b2Body *mBody;
    GLTexture *mTexture;
    std::list<PolyLine*> mLineList;
    std::list<PolyFill*> mFillList;

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
