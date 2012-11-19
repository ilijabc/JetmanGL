/*
 * GUIButton.h
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#ifndef GUIBUTTON_H_
#define GUIBUTTON_H_

#include "GUIControl.h"

class GUIButton: public GUIControl
{
public:
	GUIButton(GUIControl *parent) : GUIControl(parent, 0) { }
	//callbacks
	virtual void onDraw(GLView *view);

};

#endif /* GUIBUTTON_H_ */
