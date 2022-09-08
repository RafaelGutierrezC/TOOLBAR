#ifndef COMPILER_H_
#define COMPILER_H_

#include <map>
#include <functional>
#include "Canvas.h"
#include "Toolbar.h"
#include "LineCommand.h"
#include "Parser.h"
#include "CompilerMapInitializer.h"


class Compiler
{
public:
	Compiler(Parser* par, Canvas* canv, Toolbar* toolb): parser{par}, canvas{canv}, toolbar{toolb}, lineCP{nullptr} {}

	void compile(string comando)
	{
		lineCP = parser->buildParamsStruct(comando);
		CompilerMapInitializer::initializeLineCommandMap(canvas, toolbar, &lineCommandFactories, lineCP);
		lineCommandFactories[lineCP->commandType]()->execute();
	}

private:
	Parser *parser;
	Canvas *canvas;
	Toolbar *toolbar;
	LineCommandParse* lineCP;
	map<string,function<LineCommand*()>> lineCommandFactories;
};


#endif /* COMPILER_H_ */
