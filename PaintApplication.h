#ifndef PAINT_APPLICATION_H_
#define PAINT_APPLICATION_H_

#include <iostream>
#include <thread>
#include "Application.h"
#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Canvas.h"
#include "Toolbar.h"
#include "CLI11Parser.h"
#include "PaintCompiler.h"
#include "SaveCommandPubSub.h"
#include "fileCommandWriteThread.h"

using namespace std;


class PaintApplication: public Application
{
public:
	PaintApplication(): exit{false}
	{
		pusu = new SaveCommandPubSub();
		cliapp = new CLI::App{"Paint App"};
		lineCP = new LineCommandParse();
		parser = new CLI11Parser(cliapp,lineCP);
		canvas = new PaintCanvas();
		toolbar = new PaintToolbar();
		compiler = new PaintCompiler(pusu,this,parser,canvas,toolbar);

		ShapeFactory *rectanguloFactory = new RectanguloFactory();
		toolbar->addShapeFactory("rectangulo", rectanguloFactory);
		ShapeFactory *circuloFactory = new CirculoFactory();
		toolbar->addShapeFactory("circulo", circuloFactory);
		ShapeFactory *cuadradoFactory = new CuadradoFactory();
		toolbar->addShapeFactory("cuadrado", cuadradoFactory);

		ColorFactory *blancoFactory = new BlancoFactory();
		toolbar->addColorFactory("blanco", blancoFactory);
		ColorFactory *negroFactory = new NegroFactory();
		toolbar->addColorFactory("negro", negroFactory);
		ColorFactory *rojoFactory = new RojoFactory();
		toolbar->addColorFactory("rojo", rojoFactory);
		ColorFactory *verdeFactory = new VerdeFactory();
		toolbar->addColorFactory("verde", verdeFactory);
		ColorFactory *azulFactory = new AzulFactory();
		toolbar->addColorFactory("azul", azulFactory);
	}

	virtual ~PaintApplication()
	{
		delete cliapp;
		delete lineCP;
		delete parser;
		delete canvas;
		delete toolbar;
		delete compiler;
	}

	void runApp()
	{
		CommandQueue *commandQueue = new CommandQueue();
		auto closure = pusu->on("channel",[commandQueue](string comando){ commandQueue->pushCommand(comando); } );

		thread hilo(fileCommandWriteThread,closure,commandQueue);

		do
		{
			string comando;
			cout << ")))> ";
			getline(cin,comando);
			try
			{
				compiler->compile(comando);
			}
			catch(...)
			{
				cout << "PARSE ERROR" << endl;
			}
		}
		while(!exit);
	}

	void shutdown()
	{
		exit = true;
	}

private:
	bool exit;
	PubSub *pusu;
	CLI::App *cliapp;
	LineCommandParse *lineCP;
	Parser *parser;
	Canvas *canvas;
	Toolbar *toolbar;
	Compiler *compiler;
};


#endif /* PAINT_APPLICATION_H_ */
