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

    if (level_svg)
        loadSVGLevel(level_svg);
    else
        generateLevel();
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

    if (obj1 == mPlayer)
        printf("player A\n");
    else if (obj2 == mPlayer)
        printf("player B\n");
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
	// DEBUG DRAW FOR BOX2D
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
}

// Factory

GamePlayer *GameLevel::createPlayer(float x, float y, float w, float h, GamePlayer::Type type)
{
	GamePlayer *player = new GamePlayer(this, x, y, w, h, type);
	mGameObjectList.push_back(player);
	return player;
}

GamePlatform *GameLevel::createPlatform(float x1, float y1, float x2, float y2, GamePlatform::Type type)
{
	GamePlatform *platform = new GamePlatform(this, x1, y1, x2, y2, type);
	mGameObjectList.push_back(platform);
	return platform;
}

void GameLevel::drawBodyDebug(b2Body *body)
{
	b2Fixture *fix = body->GetFixtureList();
	while (fix)
	{
		b2Shape *shape = fix->GetShape();
		if (shape)
		{
			if (shape->GetType() == b2Shape::e_polygon)
			{
				glColor3f(1,1,1);
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
				glColor3f(1,1,1);
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

void GameLevel::generateLevel()
{
    float ww = 100;
	float hh = 50;

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body *ground = mWorld->CreateBody(&groundBodyDef);
    //ground->SetUserData(this);
	b2Vec2 vs[5];
	vs[0].Set(ww, hh);
	vs[1].Set(-ww, hh);
	vs[2].Set(-ww, -hh);
	vs[3].Set(ww, -hh);
	vs[4] = vs[0];
	b2ChainShape chain;
	chain.CreateChain(vs, 5);
    ground->CreateFixture(&chain, 0.0f);

	//GamePlatform *floor = createPlatform(-ww, -(hh - 2), ww, -hh, GamePlatform::FLOOR);
	//GamePlatform *ceiling = createPlatform(-ww, hh, ww, (hh - 2), GamePlatform::CEILING);
	int ni = 5;
	for (int i = 0; i <= ni; i++)
	{
		int nj = rand() % 3 + 1;
		for (int j = 0; j <= nj; j++)
		{
			float w = randf(15) + 6;
			float h = randf(4) + 4;
			float x = (float)i / (float)ni * (ww * 0.8 * 2) - ww * 0.8 + randf(-2, 2);
			float y = (float)j / (float)nj * (hh * 0.8 * 2) - hh * 0.8;
			float x1 = x - w;
			float y1 = y + h;
			float x2 = x + w;
			float y2 = y - h;
			GamePlatform *island = createPlatform(x1, y1, x2, y2, GamePlatform::ISLAND);
		}
	}
	mPlayer = createPlayer(10, 10, 2, 1, GamePlayer::CRAFT);
    mPlayer->setTexture(getTexture("Data/craft.png"));
}

static void solveTransform(const char *trans, float &x, float &y, float &r)
{
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
}

void GameLevel::loadSVGLevel(const char *filename)
{
    float gscale = 0.02;

    // Load
    struct SVGPath* plist;
    plist = svgParseFromFile(filename);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body *ground = mWorld->CreateBody(&groundBodyDef);

    // Use...
    for (SVGPath* it = plist; it; it = it->next)
    {
        b2Vec2 vs[it->npts];
        int i = 0;
        float x, y, w, h;
        for (i = 0; i < it->npts; ++i)
        {
            vs[i].Set(it->pts[i*2] * gscale,
                      -it->pts[i*2+1] * gscale);
        }
        if (it->closed)
            vs[i++] = vs[0];
        if (it->npts == 4)
        {
            x = (vs[0].x + vs[2].x) ? (vs[0].x + vs[2].x) / 2 : 0;
            y = (vs[0].y + vs[2].y) ? (vs[0].y + vs[2].y) / 2 : 0;
            w = fabs(vs[0].x - vs[2].x);
            h = fabs(vs[0].y - vs[2].y);
        }
        if (it->type == SVG_TYPE_IMAGE && it->link)
        {
            char img_name[64] = "Data";
            strcat(img_name, strrchr(it->link, '/'));
            GLTexture *tex = getTexture(img_name);
            if (tex)
            {
                GamePlayer *player = createPlayer(x, y, w, h, GamePlayer::CRAFT);
                player->setTexture(tex);
                if (strcmp(it->id, "player") == 0)
                    mPlayer = player;
            }
        }
        else if (it->type == SVG_TYPE_RECT)
        {
            if (it->id && strcmp(it->id, "back") == 0)
            {
                mBounds = Rect(vs[0].x, vs[2].y, vs[2].x, vs[0].y);
                b2ChainShape chain;
                chain.CreateChain(vs, i);
                ground->CreateFixture(&chain, 0.0f);
            }
            else
            {
                createPlayer(x, y, w, h, GamePlayer::BOX);
            }
        }
        else
        {
            b2ChainShape chain;
            chain.CreateChain(vs, i);
            ground->CreateFixture(&chain, 0.0f);
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
                GamePlayer *player = createPlayer(img_x, img_y, img_w, img_h, GamePlayer::CRAFT);
                player->setTexture(tex);
                mPlayer = player;
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
