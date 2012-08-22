#include "GLMath.h"


float GLVariablef::getValue() const
{
	if (isConst)
		return value;
	else
		return ((float)rand() / (float)RAND_MAX) * (maxValue - minValue) + minValue;
}


void GLVariablef::parse(const char *str)
{

}

int GLVariablei::getValue() const
{
	if (isConst)
		return value;
	else
		return (rand() % (maxValue - minValue)) + minValue;
}


