#ifndef PAINT_COMPILER_H_
#define PAINT_COMPILER_H_

#include <map>
#include <functional>
#include "Compiler.h"
#include "Canvas.h"
#include "Toolbar.h"
#include "Parser.h"
#include "LineCommand.h"


class PaintCompiler: public Compiler
{
public:
	PaintCompiler(Parser* par, Canvas* canv, Toolbar* toolb): parser{par}, canvas{canv}, toolbar{toolb}, lineCP{nullptr}
	{
		initializeLineCommandMap();
	}

	void compile(string comando)
	{
		lineCP = parser->parse(comando);
		LineCommand *lineCommand = lineCommandFactories[lineCP->commandType](lineCP);
		lineCommand->execute();
		//delete lineCommand;
	}

private:
	Parser *parser;
	Canvas *canvas;
	Toolbar *toolbar;
	LineCommandParse* lineCP;
	map<string,function<LineCommand*(LineCommandParse*)>> lineCommandFactories;

	void initializeLineCommandMap();
};


#endif /* PAINT_COMPILER_H_ */
