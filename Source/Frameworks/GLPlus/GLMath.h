#ifndef GLMATH_H
#define GLMATH_H

#include <math.h>
#include <stdlib.h>

#define GLPLUS_PI 3.14159265f
#define GLPLUS_TORAD 0.017453f
#define GLPLUS_TODEG 57.295779f


inline float glplusRandomf(float _min, float _max) { return ((float)rand() / (float)RAND_MAX) * (_max - _min) + _min; }


class GLFloat2
{
public:
	GLFloat2(): x(0.0f), y(0.0f) { }
	GLFloat2(float _x, float _y): x(_x), y(_y) { }
	GLFloat2(const GLFloat2& v): x(v.x), y(v.y) { }

	//! array indexing
	float &operator [](unsigned int i)
	{   return *(&x+i);   }

	//! array indexing
	const float &operator [](unsigned int i) const
	{	return *(&x+i);   }

	//! function call operator
	void operator ()(const float x0, const float y0)
	{	x= x0; y= y0;	}

	//! sets value
	void set(const float x0, const float y0)
	{   x = x0; y = y0; }

	//! test for equality
	bool operator==(const GLFloat2 &v) const
	{	return (x==v.x && y==v.y);	}

	//! test for inequality
	bool operator!=(const GLFloat2 &v) const
	{	return (x!=v.x || y!=v.y);	}

	//! set to value
	const GLFloat2 &operator =(const GLFloat2 &v)
	{
		x= v.x; y= v.y;
		return *this;
	}

	//! negation
	const GLFloat2 operator -(void) const
	{	return GLFloat2(-x, -y);	}

	//! addition
	const GLFloat2 operator +(const GLFloat2 &v) const
	{	return GLFloat2(x+v.x, y+v.y);	}

	//! subtraction
	const GLFloat2 operator -(const GLFloat2 &v) const
	{   return GLFloat2(x-v.x, y-v.y);	}

	//! uniform scaling
	const GLFloat2 operator *(const float num) const
	{
		//GLFloat2 temp(*this);
		//return temp*=num;
		return GLFloat2(x * num, y * num);
	}

	//! uniform scaling
	const GLFloat2 operator /(const float num) const
	{
		//GLFloat2 temp(*this);
		//return temp/=num;
		return GLFloat2(x / num, y / num);
	}

	//! addition
	const GLFloat2 &operator +=(const GLFloat2 &v)
	{
		x+=v.x;	y+=v.y;
		return *this;
	}

	//! subtraction
	const GLFloat2 &operator -=(const GLFloat2 &v)
	{
		x-=v.x;	y-=v.y;
		return *this;
	}

	//! uniform scaling
	const GLFloat2 &operator *=(const float num)
	{
		x*=num;	y*=num;
		return *this;
	}

	//! uniform scaling
	const GLFloat2 &operator /=(const float num)
	{
		x/=num;	y/=num;
		return *this;
	}

	//! dot product
	float operator *(const GLFloat2 &v) const
	{	return x*v.x + y*v.y;	}

	//! gets the length of this vector squared
	float length_squared() const
	{	return (float)(*this * *this);   }

	//! gets the length of this vector
	float length() const
	{	return (float)sqrt(*this * *this);   }

	//! normalizes this vector
	void normalize()
	{	*this/=length();	}

	//! returns the normalized vector
	GLFloat2 normalized() const
	{   return  *this/length();  }

	GLFloat2 normalized(float d) const
	{   return  *this/length() * d;  }

	//! reflects this vector about n
	/*void reflect(const GLFloat2 &n)
	{
		vector2f orig(*this);
		project(n);
		*this= *this*2 - orig;
	}*/

	//! projects this vector onto v
	/*void project(const GLFloat2 &v)
	{	*this= v * (*this * v)/(v*v);	}*/

	//! returns this vector projected onto v
	/*GLFloat2 projected(const GLFloat2 &v) const
	{   return v * (*this * v)/(v*v);	}*/

	//! computes the angle between 2 arbitrary vectors
	static inline float angle(const GLFloat2 &v1, const GLFloat2 &v2)
	{   return acosf((v1*v2) / (v1.length()*v2.length()));  }

	//! computes the angle between 2 normalized arbitrary vectors
	static inline float angle_normalized(const GLFloat2 &v1, const GLFloat2 &v2)
	{   return acosf(v1*v2);  }

	inline float angle() const
	{
		return atan2f(y, x);
	}

	inline bool isNull() const
	{
		if (x == 0 && y == 0)
			return true;
		return false;
	}

	inline void normalize(float s)
	{
		*this /= (length() / s);
	}

	inline GLFloat2 getRotated(const float a)
	{
		return GLFloat2(x * cosf(a) - y * sinf(a), x * sinf(a) + y * cosf(a));
	}

	inline GLFloat2 getNormal()
	{
		return GLFloat2(-y, x);
	}

	inline float* getPtr() { return &x; }

	inline const float* const getConstPtr() const { return &x; }

	float x;
	float y;
};


class GLFloat3
{
public:
	GLFloat3() { x=0.0f; y=0.0f; z=0.0f; }
	GLFloat3(const float _x, const float _y, const float _z) { x=_x; y=_y; z=_z; }

	void set(const float _x, const float _y, const float _z) { x=_x; y=_y; z=_z; }

    void reset() { x=0.0f; y=0.0f; z=0.0f; }

	const GLFloat3 & operator = (const GLFloat3 &v)
	{
		x = v.x; y = v.y; z = v.z;
		return *this;
	}

	//
	//vector -> vector operations
	//

	const GLFloat3 operator + (const GLFloat3 &v) const
	{
		return GLFloat3(x+v.x, y+v.y, z+v.z);
	}

	const GLFloat3 operator - (const GLFloat3 &v) const
	{
		return GLFloat3(x - v.x, y - v.y, z - v.z);
	}

	const GLFloat3 & operator += (const GLFloat3 &v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	const GLFloat3 & operator -= (const GLFloat3 &v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	const GLFloat3 & operator *= (const GLFloat3 &v)
	{
		x *= v.x; y *= v.y; z *= v.z;
		return *this;
	}

	const GLFloat3 & operator /= (const GLFloat3 &v)
	{
		x /= v.x; y /= v.y; z /= v.z;
		return *this;
	}


	//
	//vector -> scalar operations
	//

	const GLFloat3 operator * (const float &s) const
	{
		return GLFloat3(x * s, y * s, z * s);
	}

	const GLFloat3 operator / (const float &s) const
	{
		return GLFloat3(x / s, y / s, z / s);
	}

	const GLFloat3 & operator *= (const float s)
	{
		x *= s; y *= s; z *= s;
		return *this;
	}

	const GLFloat3 & operator /= (const float s)
	{
		x /= s; y /= s; z /= s;
		return *this;
	}

	float length() const
	{
		return sqrtf(x*x + y*y + z*z);
	}


	//
	//modifiers
	//

	void normalize()
	{
		*this /= length();
	}

	GLFloat3 normalized() const
	{
		return (*this / length());
	}

	bool isNull() const
	{
		if (x == 0 && y == 0 && z == 0)
			return true;
		return false;
	}

	inline float* getPtr() { return &x; }

	inline const float* getConstPtr() const { return &x; }

	//
	//matrix operations
	//
#if 0
    vector3f operator * (const matrix4f& m) const
	{
		return vector3f(
			x*m.m11 + y*m.m21 + z*m.m31,
			x*m.m12 + y*m.m22 + z*m.m32,
			x*m.m13 + y*m.m23 + z*m.m33);
	}

    const vector3f & operator *= (const matrix4f& m)
	{
	    x = x*m.m11 + y*m.m21 + z*m.m31;
	    y = x*m.m12 + y*m.m22 + z*m.m32;
        z = x*m.m13 + y*m.m23 + z*m.m33;
        return *this;
	}
#endif

    float x;
    float y;
    float z;
};


class GLRect
{
public:
	GLRect(): x1(0.0f), y1(0.0f), x2(0.0f), y2(0.0f) { }
	GLRect(float _x1, float _y1, float _x2, float _y2): x1(_x1), y1(_y1), x2(_x2), y2(_y2) { }

	inline void set(float _x1, float _y1, float _x2, float _y2) { x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2; }

	float x1;
	float y1;
	float x2;
	float y2;
};


class GLVariablef
{
public:
	GLVariablef(): value(0), minValue(0), maxValue(0), isConst(true) { }
	GLVariablef(float val): value(val), minValue(0), maxValue(0), isConst(true) { }
	GLVariablef(float min_val, float max_val): value(0), minValue(min_val), maxValue(max_val), isConst(true) { }

	inline void setValue(float val) { value = val; isConst = true; }
	inline void setValue(float min_val, float max_val) { minValue = min_val; maxValue = max_val; isConst = false; }
	inline bool getIsConst() const { return isConst; }
	float getValue() const;

	const GLVariablef & operator = (const float val)
	{
		setValue(val);
		return *this;
	}

	const GLVariablef & operator = (const double val)
	{
		setValue(val);
		return *this;
	}

	const GLVariablef & operator = (const int val)
	{
		setValue(val);
		return *this;
	}

	const GLVariablef & operator = (const float* val)
	{
		setValue(val[0], val[1]);
		return *this;
	}

	const GLVariablef & operator = (const double* val)
	{
		setValue(val[0], val[1]);
		return *this;
	}

	const GLVariablef & operator = (const int* val)
	{
		setValue(val[0], val[1]);
		return *this;
	}

	void parse(const char *str);

//private:
	float value;
	float minValue;
	float maxValue;
	bool isConst;
};


class GLVariablei
{
public:
	GLVariablei(): value(0), minValue(0), maxValue(0), isConst(true) { }
	GLVariablei(int val): value(val), minValue(0), maxValue(0), isConst(true) { }
	GLVariablei(int min_val, int max_val): value(0), minValue(min_val), maxValue(max_val), isConst(true) { }

	const GLVariablei & operator = (const float val)
	{
		setValue(val);
		return *this;
	}

	const GLVariablei & operator = (const double val)
	{
		setValue(val);
		return *this;
	}

	const GLVariablei & operator = (const int val)
	{
		setValue(val);
		return *this;
	}

	const GLVariablei & operator = (const float* val)
	{
		setValue(val[0], val[1]);
		return *this;
	}

	const GLVariablei & operator = (const double* val)
	{
		setValue(val[0], val[1]);
		return *this;
	}

	const GLVariablei & operator = (const int* val)
	{
		setValue(val[0], val[1]);
		return *this;
	}

	inline void setValue(int val) { value = val; isConst = true; }
	inline void setValue(int min_val, int max_val) { minValue = min_val; maxValue = max_val; isConst = false; }
	inline bool getIsConst() const { return isConst; }
	int getValue() const;

private:
	int value;
	int minValue;
	int maxValue;
	bool isConst;
};


#endif //GLMATH_H
