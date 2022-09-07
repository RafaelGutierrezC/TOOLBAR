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
	Compiler(Canvas* canv, Toolbar* toolb): canvas{canv}, toolbar{toolb}, lineCP{nullptr} {}

	void compile(string comando)
	{
		lineCP = Parser::buildParamsStruct(comando);
		CompilerMapInitializer::initializeLineCommandMap(canvas, toolbar, lineCommandFactories, lineCP);
		lineCommandFactories[lineCP->comando]()->execute();
	}

private:
	Canvas *canvas;
	Toolbar *toolbar;
	LineCommandParse* lineCP;
	map<string,function<LineCommand*()>> lineCommandFactories;
};


#endif /* COMPILER_H_ */
