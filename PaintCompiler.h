#ifndef PAINT_COMPILER_H_
#define PAINT_COMPILER_H_

#include <map>
#include <functional>
#include <memory>
#include "Compiler.h"
#include "Canvas.h"
#include "Toolbar.h"
#include "Parser.h"
#include "LineCommand.h"
#include "Application.h"
#include "PubSub.h"


class PaintCompiler: public Compiler
{
public:
	PaintCompiler(PubSub *pubs, Application *app, Parser *par, Canvas *canv, Toolbar *toolb):
		pusu{pubs}, application{app}, parser{par}, canvas{canv}, toolbar{toolb}, lineCP{nullptr}
	{
		initializeLineCommandMap();
	}

	virtual ~PaintCompiler()
	{
		delete lineCP;
	}

	void compile(string comando)
	{
		lineCP = parser->parse(comando);
		LineCommand *lineCommand(lineCommandFactories[lineCP->commandType](lineCP));
		lineCommand->execute();
		/*if(lineCommand->isSerializable())
		{
			pusu->emit("channel",comando);
		}*/
		delete lineCommand;
	}

private:
	PubSub *pusu;
	Application *application;
	Parser *parser;
	Canvas *canvas;
	Toolbar *toolbar;
	LineCommandParse* lineCP;
	map<string,function<LineCommand*(LineCommandParse*)>> lineCommandFactories;

	void initializeLineCommandMap();
};


#endif /* PAINT_COMPILER_H_ */
