#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <map>
#include "ShapeFactory.h"
#include "ColorFactory.h"

class Toolbar
{
public:
	Toolbar() {}

	void addShapeFactory(string key, ShapeFactory* shapeFact);

	void addColorFactory(string key, ColorFactory* colorFact);

private:
	map<string,ShapeFactory*> shapeFactories;
	ShapeFactory* getShapeFactory(string key);

	map<string,ColorFactory*> colorFactories;
	ColorFactory* getColorFactory(string key);

};

#endif /* TOOLBAR_H_ */
