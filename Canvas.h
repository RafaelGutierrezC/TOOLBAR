#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "Toolbar.h"
using namespace std;


class Canvas
{
public:
	virtual vector<Shape*>* getAllShapes() = 0;
	virtual void create(Shape *shapeType) = 0;
	virtual void list(vector<Shape*>& selectedShapes) = 0;
	virtual ~Canvas() {}
};


class PaintCanvas: public Canvas
{
public:
	PaintCanvas() {}

	virtual ~PaintCanvas()
	{
		/*for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			delete (*iter);
		}
		delete storedShapes;*/
	}

	vector<Shape*>* getAllShapes()
	{
		return &storedShapes;
	}

	void create(Shape *shapeType)
	{
		storedShapes.push_back(shapeType);
	}

	void list(vector<Shape*>& selectedShapes)
	{
		for(auto iter = selectedShapes.begin(); iter != selectedShapes.end(); iter++)
		{
			cout << (*iter)->getType() << endl;
		}
	}

private:
	vector<Shape*> storedShapes;
};


#endif /* CANVAS_H_ */
