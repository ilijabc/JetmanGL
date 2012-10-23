/*
 * GLNode.cpp
 *
 *  Created on: Jun 15, 2012
 *      Author: Ilija
 */

#include "GLNode.h"


GLNode::GLNode()
{
	refCounter = 0;
	parent = NULL;
	scale.set(1, 1, 1);
}

GLNode::~GLNode()
{
	removeAllNodes();
}


GLNode *GLNode::addNode(GLNode *node)
{
	nodeList.push_back(node);
	node->refCounter++;
	node->parent = this;
	node->onAdd(this);
	return node;
}


void GLNode::removeNode(GLNode *node)
{
	std::list<GLNode*>::iterator inode;
	for (inode = nodeList.begin(); inode != nodeList.end(); inode++)
	{
		if (*inode == node)
		{
			nodeList.erase(inode);
			node->refCounter--;
			node->onRemove(this);
			if (node->refCounter == 0)
				delete node;
			break;
		}
	}
}


void GLNode::removeAllNodes()
{
	std::list<GLNode*>::iterator inode;
	for (inode = nodeList.begin(); inode != nodeList.end(); inode++)
	{
		(*inode)->refCounter--;
		if ((*inode)->refCounter == 0)
			delete *inode;
	}
	nodeList.clear();
}


void GLNode::update(float dt)
{
	//update
	onUpdate(dt);

	//recursion
	std::list<GLNode*>::iterator inode;
	for (inode = nodeList.begin(); inode != nodeList.end(); inode++)
	{
		(*inode)->update(dt);
	}
}


void GLNode::draw(GLView *view)
{
	//draw
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation.z, 0, 0, 1);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.x, 1, 0, 0);
	glScalef(scale.x, scale.y, scale.z);
	onDraw(view);
	glPopMatrix();

	//recursion
	std::list<GLNode*>::iterator inode;
	for (inode = nodeList.begin(); inode != nodeList.end(); inode++)
	{
		(*inode)->draw(view);
	}
}



