#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Canvas.h"
#include "Toolbar.h"
#include "Parser.h"
#include "CLI11Parser.h"
#include "Compiler.h"
#include "PaintCompiler.h"
#include "LineCommandParse.h"
using namespace std;


int main()
{

	CLI::App cliapp{"Paint App"};
	LineCommandParse *lineCP = new LineCommandParse();
	Parser *parser = new CLI11Parser(&cliapp,lineCP);

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
	/*compiler->compile("create -s cuadrado -p 1.0 2.0 -e 3.0 4.0 -r rojo -b azul");
	compiler->compile("create -s cuadrado -p 4.0 2.0 -e 3.0 2.0");
	compiler->compile("create -s circulo -p 1.0 2.0 -e 6.0 1.0 -b verde");
	cout << "LIST 01" << endl;
	compiler->compile("list");
	compiler->compile("applyForeColor -i 2 -r azul");
	compiler->compile("applyBackgroundColor -i 2 -b azul");
	compiler->compile("move -i 2 -p 7.4 4.7");
	compiler->compile("remove -p 1.0 2.0");
	cout << "LIST 02" << endl;
	compiler->compile("list");*/
	compiler->compile("open -f fichero.txt");

	return 0;
}
