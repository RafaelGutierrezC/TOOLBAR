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
	virtual vector<pair<Shape*,int>>* getAllShapes() = 0;
	virtual void create(Shape *shapeType) = 0;
	virtual void list() = 0;
	virtual void select(int id) = 0;
	virtual void selectAll() = 0;
	virtual void unSelect(int id) = 0;
	virtual void unSelectAll() = 0;
	virtual ~Canvas() {}
};


class PaintCanvas: public Canvas
{
public:
	PaintCanvas() {}

	virtual ~PaintCanvas()
	{
		/*for(int i = 0; i < storedShapes.size(); i++)
		{
			delete storedShapes[i];
		}
		delete storedShapes;*/
	}

	vector<pair<Shape*,int>>* getAllShapes()
	{
		return &storedShapes;
	}

	void create(Shape *shapeType)
	{
		storedShapes.push_back(make_pair(shapeType,0));
	}

	void list()
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			if(1 == (*iter).second)
			{
				cout << (*iter).first->getShapeDescription() << endl;
				(*iter).second = 0;
			}
		}
	}

	void select(int id)
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			if((*iter).first->getId() == id)
			{
				(*iter).second = 1;
			}
		}
	}

	void selectAll()
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			(*iter).second = 1;
		}
	}

	void unSelect(int id)
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			if((*iter).first->getId() == id)
			{
				(*iter).second = 0;
			}
		}
	}

	void unSelectAll()
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			(*iter).second = 0;
		}
	}

private:
	vector<pair<Shape*,int>> storedShapes;
};


#endif /* CANVAS_H_ */
