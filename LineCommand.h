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


	void execute()
	{
		Shape *s = toolbar->getShape(shapeTyp, iniciop, finalp, toolbar->getColor(colorFren), toolbar->getColor(colorFon));
		canvas->create(s);
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

/*
class ListCommand: public LineCommand
{
public:
	ListCommand(Canvas *canv,Toolbar *toolb,string shapeType,Point inicioPunto): canvas{canv}, toolbar{toolb}, shape{} {}
	void execute();

private:
	Canvas *canvas;
	Toolbar *toolbar;
	string shape;
	Point iniciop;
};*/

#endif /* LINE_COMMAND_H_ */
