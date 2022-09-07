#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <map>
#include "ShapeFactory.h"
#include "ColorFactory.h"

class Toolbar
{
public:
	virtual void addShapeFactory(string key, ShapeFactory* shapeFact) = 0;
	virtual void addColorFactory(string key, ColorFactory* colorFact) = 0;

	virtual ShapeFactory* getShapeFactory(string key) = 0;
	virtual ColorFactory* getColorFactory(string key) = 0;

	virtual Shape* getShape(string key, Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo) = 0;
	virtual Color* getColor(string color) = 0;
};


class PaintToolbar: public Toolbar
{
public:
	PaintToolbar() {}

	void addShapeFactory(string key, ShapeFactory* shapeFact);
	void addColorFactory(string key, ColorFactory* colorFact);

	Shape* getShape(string key, Point *iniciop, Point *finalp, Color *colorFrente, Color *colorFondo);
	Color* getColor(string color);

private:
	map<string,ShapeFactory*> shapeFactories;
	map<string,ColorFactory*> colorFactories;

	ShapeFactory* getShapeFactory(string key);
	ColorFactory* getColorFactory(string key);

};

#endif /* TOOLBAR_H_ */
