#ifndef GLVIEW_H
#define GLVIEW_H

#include <GL/gl.h>
#include "GLMath.h"

class GLView
{
public:
	GLView();
	virtual ~GLView();
	
	void setup();
	
	void beginGui(int width = 0, int height = 0);
	void endGui();
	
	void beginScene2D(float left, float right, float bottom, float top);
	GLFloat2 beginScene2DWide(float height);
	void endScene2D();
	
	void beginScene3D();
	void endScene3D();
	
	void drawRect(float x1, float y1, float x2, float y2);
	void drawCube(float sx, float sy, float sz, float *color_array = 0);

	void setSize(int width, int height);
	int getWidth() const { return _width; }
	int getHeight() const { return _height; }

private:
	float _viewNear;
	float _viewFar;
	float _viewFOV;
	int _width;
	int _height;
};

#endif //GLVIEW_H
