#ifndef LINE_COMMAND_H_
#define LINE_COMMAND_H_


#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Compiler.h"
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
	CreateCommand(Canvas *canv, Toolbar *toolb, string shapeType, Point *inicioPunto, Point *finalPunto, string colorFrente, string colorFondo):
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
	ListCommand(Canvas *canv, string shapeType, Point *inicioPunto): canvas{canv}, iniciop{inicioPunto}
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
		canvas->list(shapeTyp,iniciop);
	}

private:
	Canvas *canvas;
	string shapeTyp;
	Point *iniciop;
};


class SelectCommand: public LineCommand
{
public:
	SelectCommand(Canvas *canv, int sid):
		canvas{canv}, id{sid} { }

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
	int id;
};


class SelectAllCommand: public LineCommand
{
public:
	SelectAllCommand(Canvas *canv):
		canvas{canv} { }

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
};


class UnSelectCommand: public LineCommand
{
public:
	UnSelectCommand(Canvas *canv, int sid):
		canvas{canv}, id{sid} { }

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
	int id;
};


class UnSelectAllCommand: public LineCommand
{
public:
	UnSelectAllCommand(Canvas *canv):
		canvas{canv} { }

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
};


class ApplyForeColorCommand: public LineCommand
{
public:
	ApplyForeColorCommand(Canvas *canv, Toolbar *toolb, int sid, string colorFrente):
		canvas{canv}, toolbar{toolb}, id{sid}
	{
		colorFren = colorFrente;
	}

	virtual ~ApplyForeColorCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->applyForeColor(id,toolbar->getColor(colorFren));
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	int id;
	string colorFren;
};


class ApplyBackgroundColorCommand: public LineCommand
{
public:
	ApplyBackgroundColorCommand(Canvas *canv, Toolbar *toolb, int sid, string colorFondo):
		canvas{canv}, toolbar{toolb}, id{sid}
	{
		colorFon = colorFondo;
	}

	virtual ~ApplyBackgroundColorCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->applyBackgroundColor(id,toolbar->getColor(colorFon));
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	int id;
	string colorFon;
};


class MoveCommand: public LineCommand
{
public:
	MoveCommand(Canvas *canv, int sid, Point *punto):
		canvas{canv}, id{sid}, iniciop{punto} {}

	virtual ~MoveCommand() {}


	void execute()
	{
		canvas->move(id,iniciop);
	}

private:
	Canvas *canvas;
	int id;
	Point *iniciop;
};


class RemoveCommand: public LineCommand
{
public:
	RemoveCommand(Canvas *canv, int sid, Point *punto):
		canvas{canv}, id{sid}, iniciop{punto} {}

	virtual ~RemoveCommand() {}


	void execute()
	{
		canvas->remove(id,iniciop);
	}

private:
	Canvas *canvas;
	int id;
	Point *iniciop;
};


class OpenCommand: public LineCommand
{
public:
	OpenCommand(Compiler *comp, Canvas *canv, string fichero):
		compiler{comp}, canvas{canv}
	{
		file = fichero;
	}

	virtual ~OpenCommand()
	{
		/*delete canvas;
		delete toolbar;*/
	}


	void execute()
	{
		canvas->open(compiler,file);
	}

private:
	Compiler *compiler;
	Canvas *canvas;
	string file;
};

#endif /* LINE_COMMAND_H_ */
