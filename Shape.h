#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"
#include "Color.h"
using namespace std;

class Shape
{
public:
	virtual string pintar() = 0;
};

class Rectangulo: public Shape
{
public:
	Rectangulo(Point iniciop, Point finalp, Color colorFrente, Color colorFondo):
		iniciop(iniciop),finalp(finalp),colorFrente(colorFrente),colorFondo(colorFondo){}
	string pintar(){
		return "Rectangulo";
	}
private:
	Point iniciop;
	Point finalp;
	Color colorFrente;
	Color colorFondo;
};

class Circulo: public Shape
{
public:
	Circulo(Point iniciop, Point finalp, Color colorFrente, Color colorFondo):
		iniciop(iniciop), finalp(finalp), colorFrente(colorFrente), colorFondo(colorFondo){}
	string pintar(){
			return "Circulo";
		}
private:
	Point iniciop;
	Point finalp;
	Color colorFrente;
	Color colorFondo;
};

class Cuadrado: public Shape
{
public:
	Cuadrado(Point iniciop, Point finalp, Color colorFrente, Color colorFondo):
		iniciop(iniciop), finalp(finalp), colorFrente(colorFrente), colorFondo(colorFondo){}
	string pintar(){
			return "Cuadrado";
		}
private:
	Point iniciop;
	Point finalp;
	Color colorFrente;
	Color colorFondo;
};


#endif /* SHAPE_H_ */
