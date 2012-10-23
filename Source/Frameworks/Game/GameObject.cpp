#include "GameObject.h"
#include "GameScene.h"

GameObject::GameObject(GameScene *scene, int type)
		: mScene(scene)
		, mType(type)
		, mBody(NULL)
		, mTexture(NULL)
{
}

GameObject::~GameObject()
{
	for (std::list<PolyLine*>::iterator ip = mLineList.begin(); ip != mLineList.end(); ip++)
		delete *ip;
	for (std::list<PolyFill*>::iterator il = mFillList.begin(); il != mFillList.end(); il++)
		delete *il;
}

void GameObject::onUpdate(float dt)
{
}

void GameObject::onDraw(GLView *view)
{
	//fill
	for (std::list<PolyFill*>::iterator ip = mFillList.begin(); ip != mFillList.end(); ip++)
	{
		PolyFill *poly = *ip;
		glColor4fv(poly->style.color);
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < poly->triangleCount; ++i)
		{
			GameObject::Triangle *tri = &(poly->triangleList[i]);
			glVertex2fv((float*)&(tri->a));
			glVertex2fv((float*)&(tri->b));
			glVertex2fv((float*)&(tri->c));
		}
		glEnd();
	}
	//outline
	for (std::list<PolyLine*>::iterator il = mLineList.begin(); il != mLineList.end(); il++)
	{
		PolyLine *line = *il;
		glColor4fv(line->style.color);
		glLineWidth(line->style.width);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < line->pointCount; i++)
		{
			glVertex2fv((float*)&(line->pointList[i]));
		}
		glEnd();
	}
}

void GameObject::onCollision(b2Body *other)
{
}

void GameObject::addPolyLine(b2Vec2 *pointList, int pointCount, float color[4], float width)
{
	PolyLine *line = new PolyLine(pointCount);
	memcpy(line->pointList, pointList, sizeof(b2Vec2) * pointCount);
	memcpy(line->style.color, color, sizeof(float) * 4);
	line->style.width = width;
	mLineList.push_back(line);
}

void GameObject::addPolyFill(b2Vec2 *pointList, int pointCount, float color[4])
{
}

void GameObject::addRectFill(float x1, float y1, float x2, float y2, float color[4])
{
}

GameObject::PolyLine::PolyLine(int size)
{
	pointList = new b2Vec2 [size];
	pointCount = size;
	set4fv(style.color, 1, 1, 1, 1);
	style.width = 1.0f;
}



GameObject::PolyLine::~PolyLine()
{
	delete [] pointList;
}



GameObject::PolyFill::PolyFill(int size)
{
	triangleList = new GameObject::Triangle [size];
	triangleCount = size;
	set4fv(style.color, 1, 1, 1, 1);
	style.type = 0;
}



GameObject::PolyFill::~PolyFill()
{
	delete [] triangleList;
}


