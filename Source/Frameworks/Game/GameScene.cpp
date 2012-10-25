/*
 * GameScene.cpp
 *
 *  Created on: 19.10.2012.
 *      Author: idjukic
 */

#include "GameScene.h"
#include "NanoSVG/nanosvg.h"

GameScene::GameScene(GameClient *game)
		: mGame(game)
{
	mWorld = new b2World(b2Vec2(0, -10));
	//mWorld->SetContactListener(this);
	mWorldUpdateTimeout = 0;
}

GameScene::~GameScene()
{
	delete mWorld;
}

void GameScene::update(float dt)
{
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	mWorldUpdateTimeout += dt;
	if (mWorldUpdateTimeout >= timeStep)
	{
		mWorld->Step(timeStep, velocityIterations, positionIterations);
		mWorldUpdateTimeout -= timeStep;
	}
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		(*iobj)->onUpdate(timeStep);
	}
}

void GameScene::draw(GLView *view)
{
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject* obj = *iobj;
		b2Vec2 position = obj->getPosition();
		float rotation = obj->getRotation();
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		obj->onDraw(view);
		glPopMatrix();
	}
	// DEBUG DRAW FOR BOX2D
	drawWorldDebug();
}

GameObject *GameScene::addObject(GameObject *obj, bool to_back)
{
	if (to_back)
		mGameObjectList.push_back(obj);
	else
		mGameObjectList.push_front(obj);
	return obj;
}

void GameScene::loadSVG(const char *filename)
{
	float gscale = 0.02;

	// Load
	struct SVGPath* plist;
	plist = svgParseFromFile(filename);

	// Use...
	for (SVGPath* path = plist; path; path = path->next)
	{
		GameObject *obj = NULL;
		// parse svg object
		// TODO: closed status is fixed here, but should be in nanosvg
		int vs_size = path->npts;
		if (path->closed)
			vs_size = vs_size + 1;
		b2Vec2 vs[vs_size];
		int i = 0;
		float cx = 0, cy = 0;
		float x1, y1, x2, y2;
		//rescale and calculate center anb bounds
		for (i = 0; i < vs_size; ++i)
		{
			float x = path->pts[i*2] * gscale;
			float y = -path->pts[i*2+1] * gscale;
			vs[i].Set(x, y);
			cx += x;
			cy += y;
			if (i == 0)
			{
				x1 = x2 = x;
				y1 = y2 = y;
			}
			else
			{
				if (x < x1) x1 = x;
				if (y < y1) y1 = y;
				if (x > x2) x2 = x;
				if (y > y2) y2 = y;
			}
		}
		if (cx != 0) cx = cx / (float)vs_size;
		if (cy != 0) cy = cy / (float)vs_size;
		//reposition points
		for (i = 0; i < vs_size; ++i)
		{
			vs[i].x -= cx;
			vs[i].y -= cy;
		}
		if (path->closed)
			vs[vs_size - 1] = vs[0];
		else if (vs[0] == vs[vs_size - 1])
			path->closed = 1;
		// create body
		if (path->type == SVG_TYPE_IMAGE && path->link)
		{
			char img_name[256] = "Data";
			const char *link_name = strrchr(path->link, '/');
			if (link_name == NULL)
			{
				strcat(img_name, "/");
				strcat(img_name, path->link);
			}
			else
			{
				strcat(img_name, link_name);
			}
			GLTexture *tex = getGame()->getTexture(img_name);
			if (tex)
			{
				obj = new GameObject(this, 1);
				obj->setTexture(tex);
				obj->setTextureSize(x2 - x1, y2 - y1);
				obj->setPosition(cx, cy);
			}
			else
			{
				printf("ERROR: texture '%s' not found!", img_name);
			}
		}
		else
		{
			obj = new GameObject(this, 0);
			if (path->hasStroke)
			{
				obj->addPolyLine(vs, vs_size, path->strokeColor, path->strokeWidth);
			}
			if (path->hasFill)
			{
				obj->addPolyFill(vs, path->closed ? vs_size - 1 : vs_size, path->fillColor);
			}
			obj->setPosition(cx, cy);
		}

		// create object
		if (obj)
		{
			printf("add object '%s' (%f, %f) %d %d %d\n", path->id, cx, cy, vs_size, path->closed, vs[0] == vs[vs_size-1]);
			b2Body *body = NULL;
			if (path->title)
			{
				if (strcmp(path->title, "d") == 0)
				{
					b2BodyDef bodyDef;
					bodyDef.type = b2_dynamicBody;
					bodyDef.position.Set(cx, cy);
					body = getWorld()->CreateBody(&bodyDef);
				}
				else if (strcmp(path->title, "s") == 0)
				{
					b2BodyDef bodyDef;
					bodyDef.type = b2_staticBody;
					bodyDef.position.Set(cx, cy);
					body = getWorld()->CreateBody(&bodyDef);
				}
			}
			if (body)
			{
				printf("  add shape\n");
				//connect obj <=> body
				body->SetUserData(obj);
				obj->setBody(body);
				//shape
				GameObject::PolyFill *fill = obj->getPolyFill(0);
				GameObject::PolyLine *line = obj->getPolyLine(0);
				if (fill)
				{
					for (int i = 0; i < fill->triangleCount; i++)
					{
						b2PolygonShape polyShape;
						polyShape.Set(&(fill->triangleList[i].a), 3);
						b2FixtureDef fixtureDef;
						fixtureDef.shape = &polyShape;
						fixtureDef.density = 1.0f;
						fixtureDef.friction = 0.3f;
						fixtureDef.restitution = 0.5f;
						body->CreateFixture(&fixtureDef);
					}
				}
				else if (line)
				{
					b2ChainShape chainShape;
					chainShape.CreateChain(line->pointList, line->pointCount);
					body->CreateFixture(&chainShape, 0.0f);
				}
			}
			addObject(obj, false);
		}
	}

	// Delete
	svgDelete(plist);
}

void GameScene::drawWorldDebug()
{
	for (b2Body *body = mWorld->GetBodyList(); body; body = body->GetNext())
	{
		b2Vec2 position = body->GetPosition();
		float rotation = body->GetAngle() * GLPLUS_TODEG;
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		drawBodyDebug(body);
		glPopMatrix();
	}
	for (b2Joint *joint = mWorld->GetJointList(); joint; joint = joint->GetNext())
    {
        if (joint->GetType() == e_distanceJoint)
        {
            glColor3f(1, 0, 0);
            glBegin(GL_LINES);
            glVertex2f(joint->GetAnchorA().x, joint->GetAnchorA().y);
            glVertex2f(joint->GetAnchorB().x, joint->GetAnchorB().y);
            glEnd();
        }
        else if (joint->GetType() == e_ropeJoint)
        {
            b2RopeJoint *rope = (b2RopeJoint*)joint;
            //glColor3f(0.8, 0.8, 0.8);
            glColor3f(1, 1, 1);
            glBegin(GL_LINES);
            glVertex2f(rope->GetAnchorA().x,
                       rope->GetAnchorA().y);
            glVertex2f(rope->GetAnchorB().x,
                       rope->GetAnchorB().y);
            glEnd();
        }
    }
}

void GameScene::drawBodyDebug(b2Body *body)
{
	b2Fixture *fix = body->GetFixtureList();
	glColor3f(1, 1, 1);
	while (fix)
	{
		b2Shape *shape = fix->GetShape();
		if (shape)
		{
			if (shape->GetType() == b2Shape::e_polygon)
			{
				glBegin(GL_LINE_LOOP);
				b2PolygonShape *poly = (b2PolygonShape*)shape;
				for (int i = 0; i < poly->GetVertexCount(); i++)
				{
					b2Vec2 v = poly->GetVertex(i);
					glVertex2f(v.x, v.y);
				}
				glEnd();
			}
			else if (shape->GetType() == b2Shape::e_chain)
			{
					glBegin(GL_LINE_STRIP);
					b2ChainShape *chain = (b2ChainShape*)shape;
					for (int i = 0; i < chain->m_count; i++)
					{
						b2Vec2 v = chain->m_vertices[i];
						glVertex2f(v.x, v.y);
					}
					glEnd();
			}
		}
		//next
		fix = fix->GetNext();
	}
}





