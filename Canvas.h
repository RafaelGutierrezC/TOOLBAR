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
	virtual void create(Shape *shapeType) = 0;
	//virtual void list(Shape *shapeType, Point *punto) = 0;


	// TEST
	virtual void pintarTodo() = 0;
};


class PaintCanvas: public Canvas
{
public:
	PaintCanvas() {}

	void create(Shape *shapeType)
	{
		storedShapes.push_back(shapeType);
	}

	//void list(Shape *shapeType, Point *punto);



	// TEST
	void pintarTodo()
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			cout << (*iter)->pintar() << endl;
		}
	}

private:
	vector<Shape*> storedShapes;
};


#endif /* CANVAS_H_ */
