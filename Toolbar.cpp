#include "Toolbar.h"

void Toolbar::addShapeFactory(string key, ShapeFactory* shapeFact)
{
	shapeFactories.insert(make_pair(key,shapeFact));
}

void Toolbar::addColorFactory(string key, ColorFactory* colorFact)
{
	colorFactories.insert(make_pair(key,colorFact));
}


ShapeFactory* Toolbar::getShapeFactory(string key)
{
	if(shapeFactories.find(key) == shapeFactories.end())
	{
		throw new std::exception(); //FactoryNotFoundException(key);
	}

	return shapeFactories[key];
}

ColorFactory* Toolbar::getColorFactory(string key)
{
	if(colorFactories.find(key) == colorFactories.end())
	{
		throw new std::exception(); //FactoryNotFoundException(key);
	}

	return colorFactories[key];
}
