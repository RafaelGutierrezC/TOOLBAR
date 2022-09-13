#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include <vector>
#include <fstream>
#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "Compiler.h"
using namespace std;


class Canvas
{
public:
	virtual void create(Shape *shapeType) = 0;
	virtual void list(string shapeTyp, Point *iniciop) = 0;
	virtual void select(int id) = 0;
	virtual void selectAll() = 0;
	virtual void unSelect(int id) = 0;
	virtual void unSelectAll() = 0;
	virtual void applyForeColor(int id, Color *color) = 0;
	virtual void applyBackgroundColor(int id, Color *color) = 0;
	virtual void move(int id, Point *punto) = 0;
	virtual void remove(int id, Point *punto) = 0;
	virtual void open(Compiler *compiler, const string file) = 0;
	virtual ~Canvas() {}
};


class PaintCanvas: public Canvas
{
public:
	PaintCanvas() {}

	virtual ~PaintCanvas()
	{
		for(size_t i = 0; i < storedShapes.size(); i++)
		{
			delete storedShapes[i].first;
		}
	}

	void create(Shape *shapeType)
	{
		storedShapes.push_back(make_pair(shapeType,0));
	}

	void list(string shapeTyp, Point *iniciop)
	{
		if(shapeTyp == "NULL")
		{
			if(Point(0.0,0.0) == (*iniciop))
			{
				for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
				{
					(*iter).second = 1;
				}
			}
			else
			{
				for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
				{
					if((*iniciop) == (*(*iter).first->getInitPoint()))
					{
						(*iter).second = 1;
					}
					else
					{
						(*iter).second = 0;
					}
				}
			}
		}
		else
		{
			if(Point(0.0,0.0) == (*iniciop))
			{
				for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
				{
					if(shapeTyp == (*iter).first->getType())
					{
						(*iter).second = 1;
					}
					else
					{
						(*iter).second = 0;
					}
				}
			}
			else
			{
				for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
				{
					if(shapeTyp == (*iter).first->getType() && (*iniciop) == (*(*iter).first->getInitPoint()))
					{
						(*iter).second = 1;
					}
					else
					{
						(*iter).second = 0;
					}
				}
			}
		}


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

	void applyForeColor(int id, Color *color)
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			if((*iter).first->getId() == id)
			{
				(*iter).first->setForeColor(color);
			}
		}
	}

	void applyBackgroundColor(int id, Color *color)
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			if((*iter).first->getId() == id)
			{
				(*iter).first->setBackgroundColor(color);
			}
		}
	}

	void move(int id, Point *punto)
	{
		for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
		{
			if((*iter).first->getId() == id)
			{
				(*iter).first->setInitPoint(punto);
			}
		}
	}

	void remove(int id, Point *punto)
	{
		vector<pair<Shape*,int>>::const_iterator toRemove;

		if(0 != id)
		{
			toRemove = storedShapes.end();
			for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
			{
				if((*iter).first->getId() == id)
				{
					toRemove = iter;
				}
			}
			storedShapes.erase(toRemove);
		}
		else
		{
			if(Point(0.0,0.0) != (*punto))
			{
				for(size_t i = 0; i < storedShapes.size(); i++)
				{
					toRemove = storedShapes.end();
					for(auto iter = storedShapes.begin(); iter != storedShapes.end(); iter++)
					{
						if((*punto) == (*(*iter).first->getInitPoint()))
						{
							toRemove = iter;
						}
					}
					storedShapes.erase(toRemove);
				}
			}
			else
			{
				cout << "NOT TO REMOVE" << endl;
			}
		}
	}

	void open(Compiler *compiler, const string file)
	{
		ifstream inputFile(file);
		string line;
		while(getline(inputFile,line))
		{
			compiler->compile(line);
		}
	}

private:
	vector<pair<Shape*,int>> storedShapes;
};


#endif /* CANVAS_H_ */
