#include "GameObject.h"
#include "GameScene.h"

#include "poly2tri/poly2tri.h"


GameObject::GameObject(GameScene *scene, int type)
		: mScene(scene)
		, mType(type)
		, mBody(NULL)
		, mTexture(NULL)
		, mTextureSize(1, 1)
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
		//debug triangles
#ifdef ENABLE_GAME_OBJECT_DRAW_DEBUG
		glColor3f(1, 0, 0);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < poly->triangleCount; ++i)
		{
			GameObject::Triangle *tri = &(poly->triangleList[i]);
			glVertex2fv((float*)&(tri->a));
			glVertex2fv((float*)&(tri->b));
			glVertex2fv((float*)&(tri->c));
			glVertex2fv((float*)&(tri->a));
		}
		glEnd();

#endif
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
	//image
	if (mTexture)
	{
		glColor3f(1, 1, 1);
		mTexture->drawImage(
				-mTextureSize.x, -mTextureSize.y, mTextureSize.x, mTextureSize.y,
				0, 0, 1, 1);
	}
}

void GameObject::onCollision(b2Body *other)
{
}

void GameObject::addPolyLine(b2Vec2 *pointList, int pointCount, int color, float width)
{
	PolyLine *line = new PolyLine(pointCount);
	memcpy(line->pointList, pointList, sizeof(b2Vec2) * pointCount);
	parseIntColor(color, line->style.color);
	line->style.width = width;
	mLineList.push_back(line);
}

void GameObject::addPolyFill(b2Vec2 *pointList, int pointCount, int color)
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
}

void GameObject::addRectFill(float x1, float y1, float x2, float y2, int color)
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


