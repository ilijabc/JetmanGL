#ifndef GLCAMERA_H
#define GLCAMERA_H

#include <GL/gl.h>
#include "GLMath.h"


class GLCamera
{
public:
	GLCamera();
	virtual ~GLCamera();

	void apply();

	void translate2D(const float x, const float y);
	void lookAt(const float x, const float y, const float z);

	GLFloat3 position;
	GLFloat3 rotation;
	float zoom;
};


#endif // GLCAMERA_H
