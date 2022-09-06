#ifndef SHAPEFACTORY_H_
#define SHAPEFACTORY_H_

#include "Shape.h"


class ShapeFactory
{
public:
	virtual Shape* createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo) = 0;
};


class RectanguloFactory: public ShapeFactory
{
public:
	RectanguloFactory() {}
	Shape* createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo);
};


class CirculoFactory: public ShapeFactory
{
public:
	CirculoFactory() {}
	Shape* createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo);
};


class CuadradoFactory: public ShapeFactory
{
public:
	CuadradoFactory() {}
	Shape* createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo);
};


#endif /* SHAPEFACTORY_H_ */
