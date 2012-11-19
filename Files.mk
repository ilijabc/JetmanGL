#
# Packages
#

SRC_PACKAGE_ALIEN := \
    Source/Packages/Alien/GameApp.cpp

SRC_PACKAGE_TEST := \
	Source/Packages/Test/TestClient.cpp

#
# Frameworks
#

SRC_FRAMEWORK_GAME := \
	Source/Frameworks/Game/GameClient.cpp \
    Source/Frameworks/Game/GameMain_GLFW.cpp \
    Source/Frameworks/Game/GameObject.cpp \
    Source/Frameworks/Game/GameScene.cpp

SRC_FRAMEWORK_GLPLUS := \
    Source/Frameworks/GLPlus/BMFont.cpp \
    Source/Frameworks/GLPlus/GLCamera.cpp \
    Source/Frameworks/GLPlus/GLFont.cpp \
    Source/Frameworks/GLPlus/GLMaterial.cpp \
    Source/Frameworks/GLPlus/GLMath.cpp \
    Source/Frameworks/GLPlus/GLModel.cpp \
    Source/Frameworks/GLPlus/GLNode.cpp \
    Source/Frameworks/GLPlus/GLParticleSystem.cpp \
    Source/Frameworks/GLPlus/GLTexture.cpp \
    Source/Frameworks/GLPlus/GLView.cpp \
    Source/Frameworks/GLPlus/stb_image.c

SRC_FRAMEWORK_ALPLUS := \
    Source/Frameworks/ALPlus/ALContext.cpp

SRC_FRAMEWORK_GUI := \
	Source/Frameworks/GUI/GUIButton.cpp \
	Source/Frameworks/GUI/GUIControl.cpp \
	Source/Frameworks/GUI/GUIForm.cpp

#
# Externals
#

SRC_EXTERNAL_BOX2D := \
    Source/External/Box2D/Collision/b2BroadPhase.cpp \
    Source/External/Box2D/Collision/b2CollideCircle.cpp \
    Source/External/Box2D/Collision/b2CollideEdge.cpp \
    Source/External/Box2D/Collision/b2CollidePolygon.cpp \
    Source/External/Box2D/Collision/b2Collision.cpp \
    Source/External/Box2D/Collision/b2Distance.cpp \
    Source/External/Box2D/Collision/b2DynamicTree.cpp \
    Source/External/Box2D/Collision/b2TimeOfImpact.cpp \
    Source/External/Box2D/Collision/Shapes/b2ChainShape.cpp \
    Source/External/Box2D/Collision/Shapes/b2CircleShape.cpp \
    Source/External/Box2D/Collision/Shapes/b2EdgeShape.cpp \
    Source/External/Box2D/Collision/Shapes/b2PolygonShape.cpp \
    Source/External/Box2D/Common/b2BlockAllocator.cpp \
    Source/External/Box2D/Common/b2Draw.cpp \
    Source/External/Box2D/Common/b2Math.cpp \
    Source/External/Box2D/Common/b2Settings.cpp \
    Source/External/Box2D/Common/b2StackAllocator.cpp \
    Source/External/Box2D/Common/b2Timer.cpp \
    Source/External/Box2D/Dynamics/b2Body.cpp \
    Source/External/Box2D/Dynamics/b2ContactManager.cpp \
    Source/External/Box2D/Dynamics/b2Fixture.cpp \
    Source/External/Box2D/Dynamics/b2Island.cpp \
    Source/External/Box2D/Dynamics/b2World.cpp \
    Source/External/Box2D/Dynamics/b2WorldCallbacks.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2Contact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Source/External/Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    Source/External/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2GearJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2Joint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    Source/External/Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    Source/External/Box2D/Rope/b2Rope.cpp

SRC_EXTERNAL_NANOSVG := \
    Source/External/NanoSVG/nanosvg.c

SRC_EXTERNAL_TINYXML := \
    Source/External/TinyXML/tinyxml2.cpp

SRC_EXTERNAL_INIPARSER := \
    Source/External/iniParser/dictionary.c \
    Source/External/iniParser/iniparser.c

SRC_EXTERNAL_POLY2TRI := \
	Source/External/poly2tri/common/shapes.cc \
	Source/External/poly2tri/sweep/advancing_front.cc \
	Source/External/poly2tri/sweep/cdt.cc \
	Source/External/poly2tri/sweep/sweep_context.cc \
	Source/External/poly2tri/sweep/sweep.cc
