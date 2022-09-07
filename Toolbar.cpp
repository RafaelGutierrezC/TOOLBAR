#include "Toolbar.h"

void PaintToolbar::addShapeFactory(string key, ShapeFactory* shapeFact)
{
	shapeFactories.insert(make_pair(key,shapeFact));
}

void PaintToolbar::addColorFactory(string key, ColorFactory* colorFact)
{
	colorFactories.insert(make_pair(key,colorFact));
}


ShapeFactory* PaintToolbar::getShapeFactory(string key)
{
	if(shapeFactories.find(key) == shapeFactories.end())
	{
		throw new std::exception(); //FactoryNotFoundException(key);
	}

	return shapeFactories[key];
}

ColorFactory* PaintToolbar::getColorFactory(string key)
{
	if(colorFactories.find(key) == colorFactories.end())
	{
		throw new std::exception(); //FactoryNotFoundException(key);
	}

	return colorFactories[key];
}


Shape* PaintToolbar::getShape(string key, Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo)
{
	return getShapeFactory(key)->createShape(iniciop,finalp,colorFrente,colorFondo);
}


Color* PaintToolbar::getColor(string key)
{
	return getColorFactory(key)->createColor();
}

