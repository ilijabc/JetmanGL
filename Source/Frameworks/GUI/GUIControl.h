/*
 * GUIControl.h
 *
 *  Created on: Nov 17, 2012
 *      Author: Ilija
 */

#ifndef GUICONTROL_H_
#define GUICONTROL_H_

#include "GLPlus/GLView.h"
#include "GLPlus/GLFont.h"
#include <list>
#include <string>

class GUIForm;

class GUIControl
{
public:
	enum DrawFlag {
		e_drawHoveredFlag = 0x1,
		e_drawClickedFlag = 0x2,
		e_drawFocusedFlag = 0x4
	};
	enum TextAlign {
		e_alignLeft = 0,
		e_alignCenter = 0x1,
		e_alignRight = 0x2,
		e_alignTop = 0,
		e_alignMiddle = 0x4,
		e_alignBottom = 0x8
	};
public:
	GUIControl(GUIControl *parent, int type);
	virtual ~GUIControl();
	//callbacks
	virtual void onDraw(GLView *view);
	virtual void onClick();
	//setters
	void setPosition(int left, int top, int width = -1, int height = -1);
	inline void setVisible(bool visible) { mVisible = visible; }
	inline void setEnabled(bool enabled) { mEnabled = enabled; }
	inline void setText(const char *text) { mText = text; updateTextPosition(); }
	inline void setTextAlign(int align) { mTextAlign = align; updateTextPosition(); }
	inline void setDrawFlags(int flags) { mDrawFlags = flags; }
	inline void setDrawFlag(int flag, bool set) { mDrawFlags = set ? (mDrawFlags | flag) : (mDrawFlags & (~flag)); }
	inline void setFont(GLFont *font) { mFont = font; }
	//getters
	inline GUIControl *getParent() const { return mParent; }
	inline GUIForm *getForm() const { return mForm; }
	inline int getType() const { return mType; }
	inline int getLeft() const { return mLeft; }
	inline int getTop() const { return mTop; }
	inline int getWidth() const { return mWidth; }
	inline int getHeight() const { return mHeight; }
	inline const char *getText() const { return mText.c_str(); }
	inline int getTextAlign() const { return mTextAlign; }
	inline int getDrawFlags() const { return mDrawFlags; }
	inline bool getDrawFlag(int flag) const { return (mDrawFlags & flag) == flag; }
	inline GLFont *getFont() const { return mFont; }
	//control
	GUIControl *pickControl(int x, int y);

protected:
	void drawControl(GLView *view);
	void updateTextPosition();

protected:
	GUIControl *mParent;
	std::list<GUIControl*> mControlList;
	GUIForm *mForm;
	int mType;
	int mLeft;
	int mTop;
	int mWidth;
	int mHeight;
	bool mVisible;
	bool mEnabled;
	std::string mText;
	int mTextAlign;
	int mTextPositionX;
	int mTextPositionY;
	int mDrawFlags;
	GLFont *mFont;
};

#endif /* GUICONTROL_H_ */
