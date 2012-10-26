#include "GameObject.h"
#include "GameScene.h"

#include "poly2tri/poly2tri.h"

//#define ENABLE_GAME_OBJECT_DRAW_DEBUG

GameObject::GameObject(GameScene *scene, int type)
		: mScene(scene)
		, mType(type)
		, mBody(NULL)
		, mTexture(NULL)
		, mTextureSize(1, 1)
		, mPosition(0, 0)
		, mRotation(0)
{
	strcpy(mName, "");
}

GameObject::~GameObject()
{
	for (int i = 0; i < mLineList.size(); i++)
		delete mLineList[i];
	for (int i = 0; i < mFillList.size(); i++)
		delete mFillList[i];
}

void GameObject::onUpdate(float dt)
{
	if (mBody)
	{
		mPosition = mBody->GetPosition();
		mRotation = mBody->GetAngle() * GLPLUS_TODEG;
	}
}

void GameObject::onDraw(GLView *view, unsigned int flags)
{
	if ((flags & GameScene::e_drawShapeFlag) == GameScene::e_drawShapeFlag)
	{
		//fill
		for (int i = 0; i < mFillList.size(); i++)
		{
			PolyFill *poly = mFillList[i];
			glColor4fv(poly->style.color);
			glBegin(GL_TRIANGLES);
			for (int j = 0; j < poly->triangleCount; j++)
			{
				GameObject::Triangle *tri = &(poly->triangleList[j]);
				glVertex2fv((float*)&(tri->a));
				glVertex2fv((float*)&(tri->b));
				glVertex2fv((float*)&(tri->c));
			}
			glEnd();
		}
		//outline
		for (int i = 0; i < mLineList.size(); i++)
		{
			PolyLine *line = mLineList[i];
			glColor4fv(line->style.color);
			glLineWidth(line->style.width);
			glBegin(GL_LINE_STRIP);
			for (int j = 0; j < line->pointCount; j++)
			{
				glVertex2fv((float*)&(line->pointList[j]));
			}
			glEnd();
			glLineWidth(1.0f);
		}
	}
	if ((flags & GameScene::e_drawImageFlag) == GameScene::e_drawImageFlag)
	{
		//image
		if (mTexture)
		{
			glColor3f(1, 1, 1);
			mTexture->drawImage(
					-mTextureSize.x, -mTextureSize.y, mTextureSize.x, mTextureSize.y,
					0, 0, 1, 1);
		}
	}
}

void GameObject::onCollision(b2Body *other)
{
}

int GameObject::addPolyLine(b2Vec2 *pointList, int pointCount, int color, float width)
{
	PolyLine *line = new PolyLine(pointCount);
	memcpy(line->pointList, pointList, sizeof(b2Vec2) * pointCount);
	parseIntColor(color, line->style.color);
	line->style.width = width;
	mLineList.push_back(line);
	return mLineList.size() - 1;
}

int GameObject::addPolyFill(b2Vec2 *pointList, int pointCount, int color)
{
	if (pointCount < 2)
	{
		return -1;
	}
	else if (pointCount == 3)
	{
		PolyFill *fill = new PolyFill(1);
		fill->triangleList[0].a = pointList[0];
		fill->triangleList[0].b = pointList[1];
		fill->triangleList[0].c = pointList[2];
		mFillList.push_back(fill);
		return mFillList.size() - 1;
	}
	else
	{
		std::vector<p2t::Point*> polyline;
		for (int i = 0; i < pointCount; i++)
		{
			polyline.push_back(new p2t::Point(pointList[i].x, pointList[i].y));
		}
		p2t::CDT cdt(polyline);
		cdt.Triangulate();
		std::vector<p2t::Triangle*> triangles = cdt.GetTriangles();
		PolyFill *fill = new PolyFill(triangles.size());
		for (int i = 0; i < triangles.size(); i++)
		{
			p2t::Triangle& t = *triangles[i];
			fill->triangleList[i].a.Set(t.GetPoint(0)->x, t.GetPoint(0)->y);
			fill->triangleList[i].b.Set(t.GetPoint(1)->x, t.GetPoint(1)->y);
			fill->triangleList[i].c.Set(t.GetPoint(2)->x, t.GetPoint(2)->y);
		}
		parseIntColor(color, fill->style.color);
		mFillList.push_back(fill);
		return mFillList.size() - 1;
	}
}

int GameObject::addRectFill(float x1, float y1, float x2, float y2, int color)
{
	PolyFill *fill = new PolyFill(2);
	fill->triangleList[0].a.Set(x1, y1);
	fill->triangleList[0].b.Set(x2, y1);
	fill->triangleList[0].c.Set(x2, y2);
	fill->triangleList[1].a.Set(x2, y2);
	fill->triangleList[1].b.Set(x1, y2);
	fill->triangleList[1].c.Set(x1, y1);
	parseIntColor(color, fill->style.color);
	fill->style.type = 0;
	mFillList.push_back(fill);
	return mFillList.size() - 1;
}

GameObject::PolyLine *GameObject::getPolyLine(int index)
{
	if (index < 0 || index >= mLineList.size())
		return NULL;
	return mLineList[index];
}

GameObject::PolyFill *GameObject::getPolyFill(int index)
{
	if (index < 0 || index >= mFillList.size())
		return NULL;
	return mFillList[index];
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
