#ifndef SHAPEFACTORY_H_
#define SHAPEFACTORY_H_

#include "Shape.h"


class ShapeFactory
{
public:
	virtual Shape* createShape(Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo) = 0;
	virtual ~ShapeFactory() {}
};


class RectanguloFactory: public ShapeFactory
{
public:
	RectanguloFactory() {}
	Shape* createShape(Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo);
	virtual ~RectanguloFactory() {}
};


class CirculoFactory: public ShapeFactory
{
public:
	CirculoFactory() {}
	Shape* createShape(Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo);
	virtual ~CirculoFactory() {}
};


class CuadradoFactory: public ShapeFactory
{
public:
	CuadradoFactory() {}
	Shape* createShape(Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo);
	virtual ~CuadradoFactory() {}
};


#endif /* SHAPEFACTORY_H_ */
