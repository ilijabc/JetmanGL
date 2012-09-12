/*
 * GameLevel.cpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Ilija
 */

#include "GameLevel.h"
#include "TinyXML/tinyxml2.h"

#ifdef __cplusplus
extern "C" {
#include "NanoSVG/nanosvg.h"
}
#endif

using namespace tinyxml2;

GameLevel::GameLevel(const char *level_svg)
{
	mWorld = new b2World(b2Vec2(0, -10));
	mWorld->SetContactListener(this);
	mWorldUpdateTimeout = 0;
    mPlayer = NULL;
    mBoxCounter = 0;

    loadSVGLevel(level_svg);
}

GameLevel::~GameLevel()
{
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		delete *iobj;
	}
	delete mWorld;
	for (int i = 0; i < mTexturePool.size(); i++)
    {
        delete mTexturePool[i];
    }
}

void GameLevel::BeginContact(b2Contact* contact)
{
    GameObject *obj1 = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
    GameObject *obj2 = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();
    if (obj1) obj1->onCollision(contact->GetFixtureB()->GetBody());
    if (obj2) obj2->onCollision(contact->GetFixtureA()->GetBody());
}

void GameLevel::update(float dt)
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
		(*iobj)->onUpdate(dt);
	}
}

void GameLevel::draw(GLView *view)
{
#if 0
	for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		GameObject* obj = *iobj;
		b2Vec2 position = obj->getBody()->GetPosition();
		float rotation = obj->getBody()->GetAngle() * GLPLUS_TODEG;
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		obj->onDraw(view);
		glPopMatrix();
	}
#endif
	// DEBUG DRAW FOR BOX2D
	for (b2Body *body = mWorld->GetBodyList(); body; body = body->GetNext())
	{
	    GameObject* obj = (GameObject*)body->GetUserData();
	    //if (obj && obj->getTexture())
        //    continue;
		b2Vec2 position = body->GetPosition();
		float rotation = body->GetAngle() * GLPLUS_TODEG;
		glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0, 0, 1);
		obj->onDraw(view);
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

// Factory

GameObject *GameLevel::createObject(float x, float y, float w, float h, GameObject::Type type)
{
	GameObject *obj = new GameObject(this, x, y, w, h, type);
	mGameObjectList.push_back(obj);
	if (type == GameObject::BOX)
        mBoxCounter++;
	return obj;
}

GameObject *GameLevel::createPlatform(b2Vec2 *plist, int plist_size)
{
	GameObject *obj = new GameObject(this, plist, plist_size);
	mGameObjectList.push_back(obj);
	return obj;
}

void GameLevel::destroyObject(GameObject *obj)
{
    if (obj->getType() == GameObject::BOX)
        mBoxCounter--;
#if 0
    for (std::list<GameObject*>::iterator iobj = mGameObjectList.begin(); iobj != mGameObjectList.end(); iobj++)
	{
		delete *iobj;
        mGameObjectList.erase(iobj);
        return;
	}
#endif
}

void GameLevel::drawBodyDebug(b2Body *body)
{
	GameObject *obj = (GameObject*)body->GetUserData();
	if (!obj) return;
	b2Fixture *fix = body->GetFixtureList();
	while (fix)
	{
		b2Shape *shape = fix->GetShape();
		if (shape)
		{
			if (shape->GetType() == b2Shape::e_polygon)
			{
				if (obj->mPathStyle.hasFill)
				{
					glColor4fv(obj->mPathStyle.fillColor);
					glBegin(GL_POLYGON);
					b2PolygonShape *poly = (b2PolygonShape*)shape;
					for (int i = 0; i < poly->GetVertexCount(); i++)
					{
						b2Vec2 v = poly->GetVertex(i);
						glVertex2f(v.x, v.y);
					}
					glEnd();
				}
				if (obj->mPathStyle.hasLine)
				{
					glColor4fv(obj->mPathStyle.lineColor);
					glLineWidth(obj->mPathStyle.lineWidth);
					glBegin(GL_LINE_LOOP);
					b2PolygonShape *poly = (b2PolygonShape*)shape;
					for (int i = 0; i < poly->GetVertexCount(); i++)
					{
						b2Vec2 v = poly->GetVertex(i);
						glVertex2f(v.x, v.y);
					}
					glEnd();
					glLineWidth(1);
				}
			}
			else if (shape->GetType() == b2Shape::e_chain)
			{
				if (obj->mPathStyle.hasFill)
				{
					glColor4fv(obj->mPathStyle.fillColor);
					glBegin(GL_POLYGON);
					b2ChainShape *chain = (b2ChainShape*)shape;
					for (int i = 0; i < chain->m_count; i++)
					{
						b2Vec2 v = chain->m_vertices[i];
						glVertex2f(v.x, v.y);
					}
					glEnd();
				}
				if (obj->mPathStyle.hasLine)
				{
					glColor4fv(obj->mPathStyle.lineColor);
					glLineWidth(obj->mPathStyle.lineWidth);
					glBegin(GL_LINE_STRIP);
					b2ChainShape *chain = (b2ChainShape*)shape;
					for (int i = 0; i < chain->m_count; i++)
					{
						b2Vec2 v = chain->m_vertices[i];
						glVertex2f(v.x, v.y);
					}
					glEnd();
					glLineWidth(1);
				}
			}
		}
		//next
		fix = fix->GetNext();
	}
}

static void solveTransform(const char *trans, float &x, float &y, float &r)
{
/*
    if (!trans) return;
    char *pc;
    if (strncmp(trans, "translate", 9) == 0)
    {
        pc = strchr(trans, '(') + 1;
        x = atof(pc);
        pc = strchr(pc, ',') + 1;
        y = atof(pc);
        r = 0;
    }
*/
}

void GameLevel::loadSVGLevel(const char *filename)
{
    float gscale = 0.02;

    // Load
    struct SVGPath* plist;
    plist = svgParseFromFile(filename);

    // Use...
    for (SVGPath* path = plist; path; path = path->next)
    {
		GameObject *obj = NULL;
        b2Vec2 vs[path->npts];
        int i = 0;
        float x, y, w, h;
        for (i = 0; i < path->npts; ++i)
        {
            vs[i].Set(path->pts[i*2] * gscale,
                      -path->pts[i*2+1] * gscale);
        }
        if (path->closed)
            vs[i++] = vs[0];
        if (path->npts == 4)
        {
            x = (vs[0].x + vs[2].x) ? (vs[0].x + vs[2].x) / 2 : 0;
            y = (vs[0].y + vs[2].y) ? (vs[0].y + vs[2].y) / 2 : 0;
            w = fabs(vs[0].x - vs[2].x);
            h = fabs(vs[0].y - vs[2].y);
        }
        if (path->type == SVG_TYPE_IMAGE && path->link)
        {
            char img_name[64] = "Data";
            strcat(img_name, strrchr(path->link, '/'));
            GLTexture *tex = getTexture(img_name);
            if (tex)
            {
                GameObject::Type type = GameObject::BOX;
                if (strcmp(path->id, "player") == 0)
                    type = GameObject::CRAFT;
                else if (strcmp(path->id, "alien") == 0)
                    type = GameObject::ALIEN;
                GameObject *player = createObject(x, y, w, h, type);
                player->setTexture(tex);
                if (type == GameObject::CRAFT)
                    mPlayer = player;
            }
        }
        else if (path->type == SVG_TYPE_RECT)
        {
            if (path->id && strcmp(path->id, "back") == 0)
            {
                mBounds = Rect(vs[0].x, vs[2].y, vs[2].x, vs[0].y);
				obj = createObject(vs[0].x, vs[2].y, vs[2].x - vs[0].x, vs[0].y - vs[2].y, GameObject::RECT);
            }
            else
            {
                obj = createObject(x, y, w, h, GameObject::BOX);
            }
        }
        else
        {
			obj = createPlatform(vs, i);
        }
		//apply style
		if (obj)
		{
			printf("id=%s stroke=%d:0x%X fill=%d:0x%X\n", path->id,
				path->hasStroke, path->strokeColor,
				path->hasFill, path->fillColor);
			if (path->hasStroke)
			{
				obj->mPathStyle.hasLine = true;
				parseIntColor(path->strokeColor, obj->mPathStyle.lineColor);
				obj->mPathStyle.lineWidth = path->strokeWidth;
			}
			if (path->hasFill)
			{
				obj->mPathStyle.hasFill = true;
				parseIntColor(path->fillColor, obj->mPathStyle.fillColor);
			}
		}
    }

    // Delete
    svgDelete(plist);

}
void GameLevel::loadSVGLevel_XML(const char *filename)
{
    XMLDocument doc;
    doc.LoadFile(filename);

    float g_scale = 0.02;
    float g_translate_x = 0;
    float g_translate_y = 0;
    float g_rotate = 0;

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body *ground = mWorld->CreateBody(&groundBodyDef);

    XMLElement *svg = doc.FirstChildElement("svg");
    float svg_w = svg->FloatAttribute("width") * g_scale;
    float svg_h = svg->FloatAttribute("height") * g_scale;
    if (svg)
    {
        b2Vec2 vs[5];
        vs[0].Set(svg_w, svg_h);
        vs[1].Set(0, svg_h);
        vs[2].Set(0, 0);
        vs[3].Set(svg_w, 0);
        vs[4] = vs[0];
        b2ChainShape chain;
        chain.CreateChain(vs, 5);
        ground->CreateFixture(&chain, 0.0f);
    }

    XMLElement *g = svg->FirstChildElement("g");
    solveTransform(g->Attribute("transform"), g_translate_x, g_translate_y, g_rotate);

    for (XMLElement *elem = g->FirstChildElement(); elem; elem = elem->NextSiblingElement())
    {
        printf("node: %s\n", elem->Name());
        if (strcmp(elem->Name(), "image") == 0)
        {
            char img_name[64] = "Data";
            float img_w = elem->FloatAttribute("width") * g_scale;
            float img_h = elem->FloatAttribute("height") * g_scale;
            float img_x = (elem->FloatAttribute("x") + g_translate_x) * g_scale + img_w / 2;
            float img_y = svg_h - (elem->FloatAttribute("y") + g_translate_y) * g_scale - img_h / 2;
            const char *img_link = elem->Attribute("xlink:href");
            if (img_link)
                strcat(img_name, strrchr(img_link, '/'));
            GLTexture *tex = getTexture(img_name);
            if (tex)
            {
                GameObject *obj = createObject(img_x, img_y, img_w, img_h, GameObject::CRAFT);
                obj->setTexture(tex);
                mPlayer = obj;
            }
        }
        else if (strcmp(elem->Name(), "path") == 0)
        {
            const char *path_d = elem->Attribute("d");
            if (path_d)
            {
                char path_cd[1024];
                strcpy(path_cd, path_d);
                b2Vec2 vec_list[50];
                int i = 0;
                float st_x = 0;
                float st_y = 0;
                float px, py;
                bool move_to = false;
                bool abs_coord = false;
                for (const char *xy = strtok(path_cd, " "); xy; xy = strtok(NULL, " "))
                {
                    if (strcmp(xy, "m") == 0)
                    {
                        move_to = true;
                    }
                    else if (strcmp(xy, "M") == 0)
                    {
                        move_to = true;
                        abs_coord = true;
                    }
                    else if (strcmp(xy, "z") == 0)
                    {
                        vec_list[i++] = vec_list[0];
                    }
                    else
                    {
                        float x = atof(xy);
                        float y = atof(strchr(xy, ',') + 1);
                        x = x * g_scale;
                        y = y * g_scale;
                        if (move_to)
                        {
                            st_x = x;
                            st_y = y;
                            vec_list[i].Set(st_x, st_y);
                            move_to = false;
                        }
                        else
                        {
                            if (abs_coord)
                                vec_list[i].Set(x, y);
                            else
                                vec_list[i].Set(st_x + x + px, st_y + y + py);
                        }
                        px = x;
                        py = y;
                        i++;
                    }
                }
                b2ChainShape chain;
                chain.CreateChain(vec_list, i);
                ground->CreateFixture(&chain, 0.0f);
            }
        }
    }
}

GLTexture *GameLevel::getTexture(const char *filename)
{
    for (int i = 0; i < mTexturePool.size(); i++)
    {
        if (strcmp(mTexturePool[i]->getFileName(), filename) == 0)
            return mTexturePool[i];
    }
    GLTexture *tex = new GLTexture(filename);
    mTexturePool.push_back(tex);
    return tex;
}
