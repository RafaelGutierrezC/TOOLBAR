#ifndef LINE_COMMAND_H_
#define LINE_COMMAND_H_


#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Compiler.h"
#include "Application.h"
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
	virtual bool isSerializable() = 0;
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
		delete iniciop;
		delete finalp;
	}


	void execute()
	{
		Shape *shape = toolbar->getShape(shapeTyp, iniciop, finalp, toolbar->getColor(colorFren), toolbar->getColor(colorFon));
		canvas->create(shape);
	}

	bool isSerializable()
	{
		return true;
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
		delete iniciop;
	}

	void execute()
	{
		canvas->list(shapeTyp,iniciop);
	}

	bool isSerializable()
	{
		return false;
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

	virtual ~SelectCommand() {}

	void execute()
	{
		canvas->select(id);
	}

	bool isSerializable()
	{
		return true;
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

	virtual ~SelectAllCommand() {}

	void execute()
	{
		canvas->selectAll();
	}

	bool isSerializable()
	{
		return true;
	}

private:
	Canvas *canvas;
};


class UnSelectCommand: public LineCommand
{
public:
	UnSelectCommand(Canvas *canv, int sid):
		canvas{canv}, id{sid} { }

	virtual ~UnSelectCommand() {}

	void execute()
	{
		canvas->unSelect(id);
	}

	bool isSerializable()
	{
		return true;
	}

private:
	Canvas *canvas;
	int id;
};


class UnSelectAllCommand: public LineCommand
{
public:
	UnSelectAllCommand(Canvas *canv):
		canvas{canv} {}

	virtual ~UnSelectAllCommand() {}

	void execute()
	{
		canvas->unSelectAll();
	}

	bool isSerializable()
	{
		return true;
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

	virtual ~ApplyForeColorCommand() {}

	void execute()
	{
		canvas->applyForeColor(id,toolbar->getColor(colorFren));
	}

	bool isSerializable()
	{
		return true;
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

	virtual ~ApplyBackgroundColorCommand() {}

	void execute()
	{
		canvas->applyBackgroundColor(id,toolbar->getColor(colorFon));
	}

	bool isSerializable()
	{
		return true;
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

	virtual ~MoveCommand()
	{
		delete iniciop;
	}

	void execute()
	{
		canvas->move(id,iniciop);
	}

	bool isSerializable()
	{
		return true;
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

	virtual ~RemoveCommand()
	{
		delete iniciop;
	}

	void execute()
	{
		canvas->remove(id,iniciop);
	}

	bool isSerializable()
	{
		return true;
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

	virtual ~OpenCommand() {}

	void execute()
	{
		canvas->open(compiler,file);
	}

	bool isSerializable()
	{
		return false;
	}

private:
	Compiler *compiler;
	Canvas *canvas;
	string file;
};


class ExitCommand: public LineCommand
{
public:
	ExitCommand(Application *app): application{app} {}

	virtual ~ExitCommand() {}

	void execute()
	{
		application->shutdown();
	}

	bool isSerializable()
	{
		return false;
	}

private:
	Application *application;
};


#endif /* LINE_COMMAND_H_ */
