#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <map>
#include "ShapeFactory.h"
#include "LineCommand.h"

class Toolbar
{
public:
	Toolbar() {}

	void addShapeFactory(string key, ShapeFactory* sFact);

private:
	map<string,ShapeFactory*> shapeFactories;
	ShapeFactory* getFactory(string key);

	map<string,LineCommand*> lineCommands;

};

#endif /* TOOLBAR_H_ */
