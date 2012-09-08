#include "GameObject.h"
#include "GameLevel.h"

static char ALIEN_MSG_HELLO[] = "I want to evolve,\ngive me some boxes.";
static char ALIEN_MSG_NEXT[] = "Excelent, I want more!";
static char ALIEN_MSG_FINAL[] = "I'm growing stronger!";

static char PLAYER_MSG_TUTOR1[] = "Hold left mouse button to move.";
static char PLAYER_MSG_TUTOR2[] = "Land on box to grab it.";
static char PLAYER_MSG_TUTOR3[] = "Press right mouse button\nto release the box.";

GameObject::GameObject(GameLevel *level, float x, float y, float w, float h, Type type)
{
    mLevel = level;
    mTexture = NULL;
    mBounds = Rect(-w / 2, -h / 2, w / 2, h / 2);
    mType = type;
    mPoints = 0;
    mJoint = NULL;
    mEvent = 0;
    mEventObject = NULL;
    mFule = 0;
    mMessage = NULL;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    if (type == CRAFT)
        bodyDef.fixedRotation = true;
    mBody = level->getWorld()->CreateBody(&bodyDef);
    mBody->SetUserData(this);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(w / 2, h / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f;
    mBody->CreateFixture(&fixtureDef);

    if (type == ALIEN)
        mMessage = ALIEN_MSG_HELLO;
    else if (type == CRAFT)
        mMessage = PLAYER_MSG_TUTOR1;
}

GameObject::~GameObject()
{
    //mLevel->getWorld()->DestroyBody(mBody);
}

void GameObject::onUpdate(float dt)
{
    b2Vec2 v = mBody->GetLinearVelocity();
    if (mType == CRAFT && mMessage == PLAYER_MSG_TUTOR1 && v.y > 3)
    {
        mMessage = PLAYER_MSG_TUTOR2;
    }
    else if (mType == ALIEN && mLevel->getBoxes() == 0)
    {
        b2Vec2 dv = mLevel->getPlayer()->getBody()->GetPosition() - mBody->GetPosition();
        if (dv.Length() > 5)
        {
            dv.x *= 100;
            dv.y *= 100;
            mBody->ApplyForceToCenter(dv);
        }
        if (mMessage != ALIEN_MSG_FINAL)
            mMessage = ALIEN_MSG_FINAL;
    }
    if (mEvent)
    {
        if (mType == CRAFT)
        {
            b2RopeJointDef jointDef;
            jointDef.bodyA = getBody();
            jointDef.bodyB = mEventObject->getBody();
            jointDef.localAnchorA = b2Vec2(0, mBounds.y1);
            jointDef.localAnchorB = b2Vec2(0, 0);
            jointDef.collideConnected = true;
            jointDef.maxLength = 4;
            mJoint = getBody()->GetWorld()->CreateJoint(&jointDef);
            if (mMessage == PLAYER_MSG_TUTOR2)
                mMessage = PLAYER_MSG_TUTOR3;
        }
        else if (mType == ALIEN)
        {
            mLevel->getPlayer()->releaseBox();
            mLevel->destroyObject(mEventObject);
            mLevel->getWorld()->DestroyBody(mEventObject->getBody());
            if (mMessage == ALIEN_MSG_HELLO)
                mMessage = ALIEN_MSG_NEXT;
            else
                mMessage = NULL;
        }
        mEvent = 0;
        mEventObject = NULL;
    }
}

void GameObject::onDraw(GLView *view)
{
    float u2 = 1;
    //if (mBody->GetLinearVelocity().x < 0)
    //    u2 = -1;
	glColor3f(1, 1, 1);
	if (mTexture)
    {
        glPushMatrix();
        mTexture->drawImage(mBounds.x1, mBounds.y1, mBounds.x2, mBounds.y2,
                            0, 0, u2, 1);
        glPopMatrix();
    }
    if (mMessage)
    {
        glPushMatrix();
        glRotatef(-mBody->GetAngle() * GLPLUS_TODEG, 0, 0, 1);
        glScalef(0.02, -0.02, 1);
        mLevel->getFont()->drawString(-130, -100, mMessage);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D); // TODO: needs to fix GLFont
    }
}

void GameObject::onCollision(b2Body *other)
{
    if (mType == BOX)
        return;
    if (other == mLevel->getGround())
    {
        addFule(-1);
        return;
    }
    GameObject *obj = (GameObject*)other->GetUserData();
    if (obj && obj->getType() == GameObject::BOX && !mJoint)
    {
        mEvent = 1;
        mEventObject = (GameObject*)other->GetUserData();
    }
    else
    {
        mPoints++;
    }
}

void GameObject::releaseBox()
{
    if (mJoint)
    {
        mBody->GetWorld()->DestroyJoint(mJoint);
        mJoint = NULL;
    }
    mMessage = NULL;
}
