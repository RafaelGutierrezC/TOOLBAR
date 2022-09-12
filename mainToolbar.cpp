#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Canvas.h"
#include "Toolbar.h"
#include "Parser.h"
#include "Compiler.h"
#include "PaintCompiler.h"
#include "LineCommandParse.h"
#include "CLI11.hpp" // TEST
using namespace std;


int main()
{

	CLI::App cliapp{"Paint App"};
	LineCommandParse *lineCP = new LineCommandParse();
	Parser *parser = new Parser(&cliapp,lineCP);

	Canvas *canvas = new PaintCanvas();
	Toolbar *toolbar = new PaintToolbar();

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

	Compiler *compiler = new PaintCompiler(parser,canvas,toolbar);
	compiler->compile("create -s cuadrado -p 1.0 2.0 -e 3.0 4.0 -r rojo -b azul");
	compiler->compile("create -s cuadrado -p 4.0 2.0 -e 3.0 2.0");
	compiler->compile("create -s circulo -p 1.0 2.0 -e 6.0 1.0 -b verde");
	cout << "LIST 01" << endl;
	compiler->compile("list");
	compiler->compile("applyForeColor -i 2 -r azul");
	compiler->compile("applyBackgroundColor -i 2 -b azul");
	compiler->compile("move -i 2 -p 7.4 4.7");
	compiler->compile("remove -p 1.0 2.0");
	cout << "LIST 02" << endl;
	compiler->compile("list");
	//canvas->pintarTodo();

	/*string comando = "create -s cuadrado -i 1.0 2.0 -e 3.0 4.0 -f rojo -b azul";
	string comando2 = "list -s rectangulo -v verde";

	CLI::App cliapp{"Paint App"};

	LineCommandParse *lineCP = new LineCommandParse();

	auto *create = cliapp.add_subcommand("create", "Create a Shape")->immediate_callback();
	create->callback(
			[&cliapp,lineCP,comando]()
			{
				lineCP->commandType = "create";
			}
	);

	auto * a = cliapp.add_option("-s", lineCP->shapeType, "Shape type")->required(1);
	pair<double,double> ip = make_pair(0.0,0.0);
	pair<double,double> ep = make_pair(0.0,0.0);

	cliapp.add_option("-i", ip, "X Initial Point");
	cliapp.add_option("-e", ep, "X Final Point");
	cliapp.add_option("-f", lineCP->colorFrente, "Front Color");
	cliapp.add_option("-b", lineCP->colorFondo, "Back Color");


	cliapp.parse(comando,true);
	lineCP->iniciop = new Point(ip.first,ip.second);
	lineCP->finalp = new Point(ep.first,ep.second);

	cout << lineCP->shapeType << endl
		<< lineCP->iniciop->getX() << " " << lineCP->iniciop->getY() << endl
		<< lineCP->finalp->getX() << " " << lineCP->finalp->getY() << endl
		<< lineCP->colorFrente << endl
		<< lineCP->colorFondo << endl;


	a->required(0);
	cliapp.add_option("-v", lineCP->colorFondo, "Back Color");

	cliapp.parse(comando2,true);
	lineCP->iniciop = new Point(ip.first,ip.second);
	lineCP->finalp = new Point(ep.first,ep.second);

	cout << lineCP->shapeType << endl
		<< lineCP->iniciop->getX() << " " << lineCP->iniciop->getY() << endl
		<< lineCP->finalp->getX() << " " << lineCP->finalp->getY() << endl
		<< lineCP->colorFrente << endl
		<< lineCP->colorFondo << endl;*/

	/*lineCP->commandType = "create";
	lineCP->shapeType = "cuadrado";
	lineCP->iniciop = new Point(1.0,2.0);
	lineCP->finalp = new Point(3.0,4.0);
	lineCP->colorFrente = "rojo";
	lineCP->colorFondo = "azul";*/

	return 0;
}
