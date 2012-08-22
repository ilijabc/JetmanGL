/*
 * GLMaterial.h
 *
 *  Created on: Jun 13, 2012
 *      Author: Ilija
 */

#ifndef GLMATERIAL_H_
#define GLMATERIAL_H_

class GLColor
{
public:
	GLColor(): r(1), g(1), b(1), a(1) { }
	GLColor(float _r, float _g, float _b, float _a = 1): r(_r), g(_g), b(_b), a(_a) { }

	inline void set(float _r, float _g, float _b, float _a = 1) { r = _r; g = _g; b = _b; a = _a; }
	inline float *getPtr() { return &r; }

	//predefine colors
	static GLColor White;
	static GLColor Black;
	static GLColor Red;
	static GLColor Green;
	static GLColor Blue;
	static GLColor Yellow;
	static GLColor Pink;
	static GLColor Cyan;

	//vars
	float r;
	float g;
	float b;
	float a;
};


class GLMaterial
{
public:
	GLMaterial();
	virtual ~GLMaterial();
};

#endif /* GLMATERIAL_H_ */
