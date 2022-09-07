#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Canvas.h"
#include "Toolbar.h"
#include "Compiler.h"
using namespace std;




int main()
{
	Canvas *canvas = new PaintCanvas();
	Toolbar *toolbar = new PaintToolbar();
	ShapeFactory *cuadradoFactory = new CuadradoFactory();
	toolbar->addShapeFactory("cuadrado", cuadradoFactory);
	ColorFactory *rojoFactory = new RojoFactory();
	toolbar->addColorFactory("rojo", rojoFactory);
	ColorFactory *azulFactory = new AzulFactory();
	toolbar->addColorFactory("azul", azulFactory);

	Compiler comp(canvas,toolbar);
	comp.compile("");
	canvas->pintarTodo();

	return 0;
}
