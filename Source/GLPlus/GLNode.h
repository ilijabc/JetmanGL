/*
 * GLNode.h
 *
 *  Created on: Jun 15, 2012
 *      Author: Ilija
 */

#ifndef GLNODE_H_
#define GLNODE_H_

#include "GLView.h"
#include "GLMath.h"
#include <list>


class GLNode
{
public:
	GLNode();
	virtual ~GLNode();

	GLNode *addNode(GLNode *node);
	void removeNode(GLNode *node);
	void removeAllNodes();

	inline GLNode *getParent() { return parent; }
	inline GLNode *setPosition(float x, float y, float z) { position.set(x, y, z); return this; }
	inline GLNode *setRotation(float x, float y, float z) { rotation.set(x, y, z); return this; }
	inline GLNode *setScale(float x, float y, float z) { scale.set(x, y, z); return this; }

	void update(float dt);
	void draw(GLView *view);

	//callbacks
	virtual void onAdd(GLNode *parent) { }
	virtual void onRemove(GLNode *parent) { }
	virtual void onUpdate(float dt) { }
	virtual void onDraw(GLView *view) { }

	//public attributes
	GLFloat3 	position;
	GLFloat3 	rotation;
	GLFloat3	scale;

private:
	std::list<GLNode*> nodeList;
	int refCounter;
	GLNode *parent;
};

#endif /* GLNODE_H_ */
