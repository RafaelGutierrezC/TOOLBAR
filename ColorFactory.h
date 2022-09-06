#ifndef COLORFACTORY_H_
#define COLORFACTORY_H_

#include "Color.h"

class ColorFactory
{
public:
	virtual Color* createColor() = 0;
};

class RojoFactory: public ColorFactory
{
public:
	RojoFactory() {}
	Color* createColor();
};

class VerdeFactory: public ColorFactory
{
public:
	VerdeFactory() {}
	Color* createColor();
};

class AzulFactory: public ColorFactory
{
public:
	AzulFactory() {}
	Color* createColor();
};


#endif /* COLORFACTORY_H_ */
