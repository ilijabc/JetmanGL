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
	virtual void onDraw(GLView *view, unsigned int flags);
	virtual void onCollision(b2Body *other);
    //setters
	inline void setBody(b2Body *body) { mBody = body; }
	inline void setTexture(GLTexture *tex) { mTexture = tex; }
	inline void setTextureSize(float w, float h) { mTextureSize.Set(w / 2, h / 2); }
	inline void setPosition(const b2Vec2 &pos) { mPosition = pos; }
	inline void setPosition(float x, float y) { mPosition.Set(x, y); }
	inline void setRotation(float rot) { mRotation = rot; }
	inline void setName(const char *name) { strcpy(mName, name); }
	inline void setBounds(float x1, float y1, float x2, float y2) { mBounds.set(x1, y1, x2, y2); }
	//getters
	inline b2Body *getBody() const { return mBody; }
	inline GLTexture *getTexture() const { return mTexture; }
	inline b2Vec2 getTextureSize() const { return mTextureSize; }
    inline int getType() const { return mType; }
    inline const b2Vec2 &getPosition() const { return mPosition; }
    inline float getRotation() const { return mRotation; }
    inline const char *getName() const { return mName; }
    inline Rect getBounds() const { return mBounds; }
    //geomtry
    int addPolyLine(b2Vec2 *pointList, int pointCount, int color = 0xFFFFFFFF, float width = 1.0f);
    int addPolyFill(b2Vec2 *pointList, int pointCount, int color = 0xFFFFFFFF);
    int addRectFill(float x1, float y1, float x2, float y2, int color = 0xFFFFFFFF);
    PolyLine *getPolyLine(int index);
    PolyFill *getPolyFill(int index);
    inline int getPolyLineCount() const { return mLineList.size(); }
    inline int getPolyFillCount() const { return mFillList.size(); }

private:
    GameScene *mScene;
    int mType;
	b2Body *mBody;
    GLTexture *mTexture;
    b2Vec2 mTextureSize;
    std::vector<PolyLine*> mLineList;
    std::vector<PolyFill*> mFillList;
    b2Vec2 mPosition;
    float mRotation;
    char mName[250];
    Rect mBounds;
};

#endif // GAMEOBJECT_H
