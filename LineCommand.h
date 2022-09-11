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
		vector<pair<Shape*,int>> *allShapes = canvas->getAllShapes();

		if(shapeTyp == "NULL")
		{
			if(iniciop->getX() == 0.0 || iniciop->getY() == 0.0)
			{
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					(*iter).second = 1;
				}
			}
			else
			{
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					if(iniciop->getX() ==  (*iter).first->getInitPoint()->getX() && iniciop->getY() ==  (*iter).first->getInitPoint()->getY())
					{
						(*iter).second = 1;
					}
				}
			}
		}
		else
		{
			if(iniciop->getX() == 0.0 || iniciop->getY() == 0.0)
			{
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					if(shapeTyp == (*iter).first->getType())
					{
						(*iter).second = 1;
					}
				}
			}
			else
			{
				for(auto iter = allShapes->begin(); iter != allShapes->end(); iter++)
				{
					if(shapeTyp == (*iter).first->getType() && iniciop->getX() ==  (*iter).first->getInitPoint()->getX() && iniciop->getY() ==  (*iter).first->getInitPoint()->getY())
					{
						(*iter).second = 1;
					}
				}
			}
		}

		canvas->list();
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	string shapeTyp;
	Point *iniciop;
};


class SelectCommand: public LineCommand
{
public:
	SelectCommand(Canvas* canv, Toolbar* toolb, int sid):
		canvas{canv}, toolbar{toolb}, id{sid} { }

	virtual ~SelectCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->select(id);
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	int id;
};


class SelectAllCommand: public LineCommand
{
public:
	SelectAllCommand(Canvas* canv, Toolbar* toolb):
		canvas{canv}, toolbar{toolb} { }

	virtual ~SelectAllCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->selectAll();
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
};


class UnSelectCommand: public LineCommand
{
public:
	UnSelectCommand(Canvas* canv, Toolbar* toolb, int sid):
		canvas{canv}, toolbar{toolb}, id{sid} { }

	virtual ~UnSelectCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->unSelect(id);
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	int id;
};


class UnSelectAllCommand: public LineCommand
{
public:
	UnSelectAllCommand(Canvas* canv, Toolbar* toolb):
		canvas{canv}, toolbar{toolb} { }

	virtual ~UnSelectAllCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->unSelectAll();
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
};


#endif /* LINE_COMMAND_H_ */
