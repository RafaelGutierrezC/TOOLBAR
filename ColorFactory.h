#ifndef COLORFACTORY_H_
#define COLORFACTORY_H_

#include "Color.h"

class ColorFactory
{
public:
	virtual Color* createColor() = 0;
	virtual ~ColorFactory() {}
};


class BlancoFactory: public ColorFactory
{
public:
	BlancoFactory() {}
	Color* createColor();
	virtual ~BlancoFactory() {}
};

class NegroFactory: public ColorFactory
{
public:
	NegroFactory() {}
	Color* createColor();
	virtual ~NegroFactory() {}
};


class RojoFactory: public ColorFactory
{
public:
	RojoFactory() {}
	Color* createColor();
	virtual ~RojoFactory() {}
};


class VerdeFactory: public ColorFactory
{
public:
	VerdeFactory() {}
	Color* createColor();
	virtual ~VerdeFactory() {}
};


class AzulFactory: public ColorFactory
{
public:
	AzulFactory() {}
	Color* createColor();
	virtual ~AzulFactory() {}
};


#endif /* COLORFACTORY_H_ */
