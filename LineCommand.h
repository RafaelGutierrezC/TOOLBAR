#ifndef LINE_COMMAND_H_
#define LINE_COMMAND_H_


#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Canvas.h"
#include "Toolbar.h"
using namespace std;


template <typename T, typename... Args>
T* buildLineCommand(Args&&... args)
{
    return new T(forward<Args>(args)...);
}


class LineCommand
{
public:
	virtual void execute() = 0;
	virtual ~LineCommand() {}
};


class CreateCommand: public LineCommand
{
public:
	CreateCommand(Canvas* canv, Toolbar* toolb, string shapeType, Point *inicioPunto, Point *finalPunto, string colorFrente, string colorFondo):
		canvas{canv}, toolbar{toolb}, iniciop{inicioPunto}, finalp{finalPunto}
	{
		shapeTyp = shapeType;
		colorFren = colorFrente;
		colorFon = colorFondo;
	}

	virtual ~CreateCommand()
	{
		/*delete canvas;
		delete toolbar;
		delete shapeTyp;
		delete iniciop;
		delete finalp;
		delete colorFren;
		delete colorFon;*/
	}


	void execute()
	{
		Shape *shape = toolbar->getShape(shapeTyp, iniciop, finalp, toolbar->getColor(colorFren), toolbar->getColor(colorFon));
		canvas->create(shape);
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	string shapeTyp;
	Point *iniciop;
	Point *finalp;
	string colorFren;
	string colorFon;
};


class ListCommand: public LineCommand
{
public:
	ListCommand(Canvas *canv,Toolbar *toolb,string shapeType,Point *inicioPunto): canvas{canv}, toolbar{toolb}, iniciop{inicioPunto}
	{
		shapeTyp = shapeType;
	}

	virtual ~ListCommand()
	{
		/*delete canvas;
		delete toolbar;
		delete shapeTyp;
		delete iniciop;*/
	}

	void execute()
	{
		vector<Shape*> *allShapes = canvas->getAllShapes();
		vector<Shape*> selectedShapes;

		if(shapeTyp == "NULL")
		{
			if(iniciop->getX() == 0.0 || iniciop->getY() == 0.0)
			{
				cout << "LIST ALL" << endl;
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					selectedShapes.push_back((*iter));
				}
			}
			else
			{
				cout << "LIST BY POINT" << endl;
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					if(iniciop->getX() ==  (*iter)->getInitPoint()->getX() && iniciop->getY() ==  (*iter)->getInitPoint()->getY())
					{
						selectedShapes.push_back((*iter));
					}
				}
			}
		}
		else
		{
			if(iniciop->getX() == 0.0 || iniciop->getY() == 0.0)
			{
				cout << "LIST BY SHAPE" << endl;
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					if(shapeTyp == (*iter)->getType())
					{
						selectedShapes.push_back((*iter));
					}
				}
			}
			else
			{
				cout << "LIST BY SHAPE AND POINT" << endl;
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					if(shapeTyp == (*iter)->getType() && iniciop->getX() ==  (*iter)->getInitPoint()->getX() && iniciop->getY() ==  (*iter)->getInitPoint()->getY())
					{
						selectedShapes.push_back((*iter));
					}
				}
			}
		}

		canvas->list(selectedShapes);
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	string shapeTyp;
	Point *iniciop;
};

#endif /* LINE_COMMAND_H_ */
