# Source

SRC_GAME := \
    Source/Game/GameApp.cpp \
    Source/Game/GameLevel.cpp \
    Source/Game/GameMain_GLFW.cpp \
    Source/Game/GameObject.cpp

SRC_GLPLUS := \
    Source/GLPlus/BMFont.cpp \
    Source/GLPlus/GLCamera.cpp \
    Source/GLPlus/GLFont.cpp \
    Source/GLPlus/GLMaterial.cpp \
    Source/GLPlus/GLMath.cpp \
    Source/GLPlus/GLModel.cpp \
    Source/GLPlus/GLNode.cpp \
    Source/GLPlus/GLParticleSystem.cpp \
    Source/GLPlus/GLTexture.cpp \
    Source/GLPlus/GLView.cpp \
    Source/GLPlus/stb_image.c

SRC_ALPLUS := \
    Source/ALPlus/ALContext.cpp

# External

SRC_BOX2D := \
    External/Box2D/Collision/b2BroadPhase.cpp \
    External/Box2D/Collision/b2CollideCircle.cpp \
    External/Box2D/Collision/b2CollideEdge.cpp \
    External/Box2D/Collision/b2CollidePolygon.cpp \
    External/Box2D/Collision/b2Collision.cpp \
    External/Box2D/Collision/b2Distance.cpp \
    External/Box2D/Collision/b2DynamicTree.cpp \
    External/Box2D/Collision/b2TimeOfImpact.cpp \
    External/Box2D/Collision/Shapes/b2ChainShape.cpp \
    External/Box2D/Collision/Shapes/b2CircleShape.cpp \
    External/Box2D/Collision/Shapes/b2EdgeShape.cpp \
    External/Box2D/Collision/Shapes/b2PolygonShape.cpp \
    External/Box2D/Common/b2BlockAllocator.cpp \
    External/Box2D/Common/b2Draw.cpp \
    External/Box2D/Common/b2Math.cpp \
    External/Box2D/Common/b2Settings.cpp \
    External/Box2D/Common/b2StackAllocator.cpp \
    External/Box2D/Common/b2Timer.cpp \
    External/Box2D/Dynamics/b2Body.cpp \
    External/Box2D/Dynamics/b2ContactManager.cpp \
    External/Box2D/Dynamics/b2Fixture.cpp \
    External/Box2D/Dynamics/b2Island.cpp \
    External/Box2D/Dynamics/b2World.cpp \
    External/Box2D/Dynamics/b2WorldCallbacks.cpp \
    External/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    External/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    External/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    External/Box2D/Dynamics/Contacts/b2Contact.cpp \
    External/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    External/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    External/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    External/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    External/Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    External/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    External/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    External/Box2D/Dynamics/Joints/b2GearJoint.cpp \
    External/Box2D/Dynamics/Joints/b2Joint.cpp \
    External/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    External/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    External/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    External/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    External/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    External/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    External/Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    External/Box2D/Rope/b2Rope.cpp

SRC_NANOSVG := \
    External/NanoSVG/nanosvg.c

SRC_TINYXML := \
    External/TinyXML/tinyxml2.cpp

SRC_INIPARSER := \
    External/iniParser/dictionary.c \
    External/iniParser/iniparser.c
