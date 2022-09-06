#include "ShapeFactory.h"

Shape* RectanguloFactory::createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo)
{
	return new Rectangulo(iniciop,finalp,colorFrente,colorFondo);
}


Shape* CirculoFactory::createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo)
{
	return new Circulo(iniciop,finalp,colorFrente,colorFondo);
}


Shape* CuadradoFactory::createShape(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo)
{
	return new Cuadrado(iniciop,finalp,colorFrente,colorFondo);
}
