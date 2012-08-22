#include "GLCamera.h"
#include <math.h>


GLCamera::GLCamera()
{
	position.x = 0;
	position.y = 0;
	position.z = 0;
	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;
	zoom = 0;
}

GLCamera::~GLCamera()
{
	//dtor
}


void GLCamera::apply()
{
	glTranslatef(0, 0, zoom);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);
	glTranslatef(-position.x, -position.y, -position.z);
}


void GLCamera::translate2D(const float x, const float y)
{
	/*vector2f v = vector2f(x, y).getRotated(-mDegToRad(rotation.z));
	position.x += v.x;
	position.y += v.y;*/
	position.x += cosf(rotation.z * GLPLUS_TORAD);
	position.y += sinf(rotation.z * GLPLUS_TORAD);
}


void GLCamera::lookAt(const float x, const float y, const float z)
{
    //rotation.z = 90 - mRadToDeg(atan2(y - position.y, x - position.x));
    //rotation.x = mRadToDeg(atan2(position.z - z, (sqrt(mPow2(x - position.x) + mPow2(y - position.y)))))-90;
}
