#include "Toolbar.h"

void Toolbar::addShapeFactory(string key, ShapeFactory* sFact)
{
	shapeFactories.insert(make_pair(key,sFact));
}


ShapeFactory* Toolbar::getFactory(string key)
{
	if(shapeFactories.find(key) == shapeFactories.end())
	{
		throw new std::exception(); //FactoryNotFoundException(key);
	}

	return shapeFactories[key];
}
