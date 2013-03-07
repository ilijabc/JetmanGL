/*
 * GameScene.cpp
 *
 *  Created on: 19.10.2012.
 *      Author: idjukic
 */

#include "GameScene.h"
#include "NanoSVG/nanosvg.h"

GameScene::GameScene(AppClient *game)
		: mGame(game)
		, mDrawFlags(e_drawShapeFlag | e_drawImageFlag)
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
		if (!obj->isVisible())
			continue;
		b2Vec2 position = obj->getPosition();
		float rotation = obj->getRotation();
		b2Vec2 offset = obj->getPositionOffset();
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		glTranslatef(offset.x, offset.y, 0);
		obj->onDraw(view, mDrawFlags);
		glPopMatrix();
	}
	//bounds
	if ((mDrawFlags & e_drawBoundsFlag) == e_drawBoundsFlag)
	{
		for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
		{
			Rect bounds = (*iobj)->getBounds();
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 0);
			glVertex2f(bounds.x1, bounds.y1);
			glVertex2f(bounds.x2, bounds.y1);
			glVertex2f(bounds.x2, bounds.y2);
			glVertex2f(bounds.x1, bounds.y2);
			glEnd();
		}
	}
	// DEBUG DRAW FOR BOX2D
	if ((mDrawFlags & e_drawBox2DFlag) == e_drawBox2DFlag)
	{
		drawWorldDebug();
	}
}

GameObject *GameScene::addObject(GameObject *obj, bool to_back)
{
	if (to_back)
		mGameObjectList.push_back(obj);
	else
		mGameObjectList.push_front(obj);
	return obj;
}

GameObject *GameScene::getObjectByName(const char *name)
{
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		if (strcmp((*iobj)->getName(), name) == 0)
			return (*iobj);
	}
	return NULL;
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
		std::vector<b2Vec2> vs;
		int i = 0;
		float cx = 0, cy = 0;
		float x1, y1, x2, y2;
		//rescale and calculate center anb bounds
		for (i = 0; i < path->npts; ++i)
		{
			float x = path->pts[i*2] * gscale;
			float y = -path->pts[i*2+1] * gscale;
			//discard repeated points
			if (i > 0 && vs[i - 1].x == x && vs[i - 1].y == y)
				continue;
			vs.push_back(b2Vec2(x, y));
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
		if (x1 + x2 != 0) cx = (x1 + x2) / 2;
		if (y1 + y2 != 0) cy = (y1 + y2) / 2;
		//reposition points
		for (i = 0; i < vs.size(); ++i)
		{
			vs[i].x -= cx;
			vs[i].y -= cy;
		}
		//fix closing points
		if (vs[0] == vs[vs.size() - 1])
		{
			path->closed = 1;
			vs.pop_back();
		}

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
			}
			else
			{
				printf("ERROR: texture '%s' not found!", img_name);
			}
		}
		else
		{
			obj = new GameObject(this, 0);
			// stroke
			obj->addPolyLine(&(vs[0]), vs.size(), path->strokeColor, path->strokeWidth);
			if (path->hasStroke)
				obj->setHasLine(true);
			// fill
			obj->addPolyFill(&(vs[0]), vs.size(), path->fillColor);
			if (path->hasFill)
				obj->setHasFill(true);
			//circle
			// TODO: circles are still not proper handled by nanosvg
			//       maybe to analyze geometry for now...
#if 0
			if (path->type == SVG_TYPE_CIRCLE)
			{
				float rx = fabs(x2 - x1) / 2;
				float ry = fabs(y2 - y1) / 2;
				if (rx == ry)
					obj->setRadius(rx);
			}
#else
			obj->setRadius(fabs(x2 - x1) / 2);
#endif
		}

		// create object
		if (obj)
		{
			obj->setPosition(cx, cy);
			obj->setBounds(x1, y1, x2, y2);
			if (path->id)
				obj->setName(path->id);
			if (path->description)
				obj->parseProperties(path->description);
#ifdef DEBUG_SVG
			printf("add object '%s' (%f, %f) %f %f %f %f\n", path->id, cx, cy, x1, y1, x2, y2);
#endif
			addObject(obj, false);
		}
	}

	// Delete
	svgDelete(plist);

	// build game world and connect objects
	processGameObjects();
}

void GameScene::processGameObjects()
{
#ifdef DEBUG_SVG
	// print obj info
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject *obj = *iobj;
		printf("OBJECT: %s\n", obj->getName());
		for (int i = 0; i < obj->getPropertiesCount(); i++)
		{
			GameObject::Property *prop = obj->getProperty(i);
			printf("  %s = %s\n", prop->getName(), prop->getValue());
		}
	}
#endif
	// create bodies
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject *obj = *iobj;
		GameObject::Property *bodyProp = obj->findProperty("body");
		if (bodyProp)
		{
			b2Body *body = NULL;
			b2Vec2 pos = obj->getPosition();
			if (bodyProp->isValue("static"))
			{
				b2BodyDef bodyDef;
				bodyDef.type = b2_staticBody;
				bodyDef.position.Set(pos.x, pos.y);
				body = getWorld()->CreateBody(&bodyDef);
			}
			else if (bodyProp->isValue("dynamic"))
			{
				b2BodyDef bodyDef;
				bodyDef.type = b2_dynamicBody;
				bodyDef.position.Set(pos.x, pos.y);
				body = getWorld()->CreateBody(&bodyDef);
			}
			if (body)
			{
				obj->setBody(body);
				body->SetUserData(obj);
			}
		}
		GameObject::Property *visibleProp = obj->findProperty("visible");
		if (visibleProp)
		{
			if (visibleProp->isValue("no"))
				obj->setVisible(false);
		}
	}
	// attach mounts
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject *obj = *iobj;
		GameObject::Property *attachProp = obj->findProperty("attach");
		if (attachProp)
		{
			if (obj->getBody())
			{
				printf("ERROR: Object '%s' already has a body!\n", obj->getName());
				continue;
			}
			GameObject *obj2 = getObjectByName(attachProp->getValue());
			if (obj2)
			{
				b2Vec2 offset = obj->getPosition() - obj2->getPosition();
				if (obj2->getBody())
				{
					obj->setBody(obj2->getBody());
					obj->setPositionOffset(offset.x, offset.y);
				}
				else
					printf("ERROR: Object '%s' (needed by '%s') does not posess a body!\n", obj2->getName(), obj->getName());
			}
		}
	}
	// create shapes
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject *obj = *iobj;
		b2Body *body = obj->getBody();
		b2Vec2 offset = obj->getPositionOffset();
		float density = 1.0f;
		float friction = 0.3f;
		float restitution = 0.5f;
		if (body)
		{
			GameObject::PolyFill *fill = obj->getPolyFill(0);
			GameObject::PolyLine *line = obj->getPolyLine(0);
			GameObject::Property *shapeProp = obj->findProperty("shape");
			if (shapeProp)
			{
				GameObject::Property *densityProp = obj->findProperty("density");
				GameObject::Property *frictionProp = obj->findProperty("friction");
				GameObject::Property *restitutionProp = obj->findProperty("restitution");
				if (densityProp)
					density = densityProp->getFloatValue();
				if (frictionProp)
					friction = frictionProp->getFloatValue();
				if (restitutionProp)
					restitution = restitutionProp->getFloatValue();
				int shapeType = 0;
				if (shapeProp->isValue("auto"))
				{
					if (obj->getHasFill())
						shapeType = 0;
					else if (obj->getHasLine())
						shapeType = 1;
				}
				else if (shapeProp->isValue("polygon"))
					shapeType = 0;
				else if (shapeProp->isValue("chain"))
					shapeType = 1;
				else if (shapeProp->isValue("circle"))
					shapeType = 2;
				// make shape
				switch (shapeType)
				{
				case 0: // polygon
					if (fill)
					{
						for (int i = 0; i < fill->triangleCount; i++)
						{
							b2PolygonShape polyShape;
							b2Vec2 triangle[3] = {
									fill->triangleList[i].a + offset,
									fill->triangleList[i].b + offset,
									fill->triangleList[i].c + offset
							};
							polyShape.Set(triangle, 3);
							b2FixtureDef fixtureDef;
							fixtureDef.shape = &polyShape;
							fixtureDef.density = density;
							fixtureDef.friction = friction;
							fixtureDef.restitution = restitution;
							body->CreateFixture(&fixtureDef);
						}
					}
					else
						printf("ERROR: Object '%s' needs a fill to be a polygon!\n", obj->getName());
					break;
				case 1: // chain
					if (line)
					{
						b2ChainShape chainShape;
						b2Vec2 points[line->pointCount];
						for (int i = 0; i < line->pointCount; i++)
							points[i] = line->pointList[i] + offset;
						chainShape.CreateChain(points, line->pointCount);
						body->CreateFixture(&chainShape, 0.0f);
					}
					else
						printf("ERROR: Object '%s' needs a line to be a chain!\n", obj->getName());
					break;
				case 2: // circle
					if (obj->getRadius() > 0)
					{
						// TODO: add circle shape
						b2CircleShape circleShape;
						circleShape.m_p = offset;
						circleShape.m_radius = obj->getRadius();
						b2FixtureDef fixtureDef;
						fixtureDef.shape = &circleShape;
						fixtureDef.density = density;
						fixtureDef.friction = friction;
						fixtureDef.restitution = restitution;
						body->CreateFixture(&fixtureDef);
					}
					else
						printf("ERROR: Object '%s' needs a radius to be a circle!\n", obj->getName());
					break;
				}
			}
		}
	}
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
			else if (shape->GetType() == b2Shape::e_circle)
			{
				glBegin(GL_LINE_LOOP);
				b2CircleShape *circle = (b2CircleShape*)shape;
				int segments = 18;
				for (int i = 0; i < segments; i++)
				{
					float t = ((float)i / (float)segments) * GLPLUS_PI * 2;
					float r = circle->m_radius;
					b2Vec2 v = circle->m_p;
					glVertex2f(cosf(t) * r + v.x, sinf(t) * r + v.y);
				}
				glEnd();
			}
		}
		//next
		fix = fix->GetNext();
	}
}





