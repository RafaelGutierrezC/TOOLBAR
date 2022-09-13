#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <sstream>
#include "Point.h"
#include "Color.h"
using namespace std;


static int idCount = 0;

class Shape
{
public:
	virtual string getShapeDescription() = 0;
	virtual string getType() = 0;
	virtual Point* getInitPoint() = 0;
	virtual void setInitPoint(Point *punto) = 0;
	virtual void setForeColor(Color *color) = 0;
	virtual void setBackgroundColor(Color *color) = 0;
	virtual int getId() = 0;
	virtual ~Shape() {}

};


class Rectangulo: public Shape
{
public:
	Rectangulo(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo):
		id{++idCount}, iniciop(iniciop),finalp(finalp),colorFrente(colorFrente),colorFondo(colorFondo) {}

	virtual ~Rectangulo()
	{
		delete colorFrente;
		delete colorFondo;
	}

	string getShapeDescription()
	{
		stringstream description;
		description << "Rectángulo. ID: " << to_string(id) << endl
				<< "Punto inicial: (" << to_string(iniciop.getX()) << "," << to_string(iniciop.getY()) << ")." << endl
				<< "Punto final: (" << to_string(finalp.getX()) << "," << to_string(finalp.getY()) << ")." << endl
				<< "Color interior: " << colorFrente->getColor() << "." << endl
				<< "Color de fondo: " << colorFondo->getColor() << "." << endl;

		return description.str();
	}

	string getType() { return "rectangulo"; }
	Point* getInitPoint() { return &iniciop; }
	int getId() { return id; }
	void setInitPoint(Point *punto)
	{
		iniciop.setX(punto->getX());
		iniciop.setY(punto->getY());
	}

	void setForeColor(Color *color)
	{
		delete colorFrente;
		colorFrente = color;
	}

	void setBackgroundColor(Color *color)
	{
		delete colorFondo;
		colorFondo = color;
	}

private:
	int id;
	Point iniciop;
	Point finalp;
	Color *colorFrente;
	Color *colorFondo;
};


class Circulo: public Shape
{
public:
	Circulo(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo):
		id{++idCount}, iniciop(iniciop), finalp(finalp), colorFrente(colorFrente), colorFondo(colorFondo) {}

	string getShapeDescription()
	{
		stringstream description;
		description << "Círculo. ID: " << to_string(id) << endl
				<< "Punto inicial: (" << to_string(iniciop.getX()) << "," << to_string(iniciop.getY()) << ")." << endl
				<< "Punto final: (" << to_string(finalp.getX()) << "," << to_string(finalp.getY()) << ")." << endl
				<< "Color interior: " << colorFrente->getColor() << "." << endl
				<< "Color de fondo: " << colorFondo->getColor() << "." << endl;

		return description.str();
	}

	virtual ~Circulo()
	{
		delete colorFrente;
		delete colorFondo;
	}

	string getType() { return "circulo"; }
	Point* getInitPoint() { return &iniciop; }
	int getId() { return id; }
	void setInitPoint(Point *punto)
	{
		iniciop.setX(punto->getX());
		iniciop.setY(punto->getY());
	}

	void setForeColor(Color *color)
	{
		delete colorFrente;
		colorFrente = color;
	}

	void setBackgroundColor(Color *color)
	{
		delete colorFondo;
		colorFondo = color;
	}

private:
	int id;
	Point iniciop;
	Point finalp;
	Color *colorFrente;
	Color *colorFondo;
};


class Cuadrado: public Shape
{
public:
	Cuadrado(Point iniciop, Point finalp, Color *colorFrente, Color *colorFondo):
		id{++idCount}, iniciop(iniciop), finalp(finalp), colorFrente(colorFrente), colorFondo(colorFondo) {}

	virtual ~Cuadrado()
	{
		delete colorFrente;
		delete colorFondo;
	}

	string getShapeDescription()
	{
		stringstream description;
		description << "Cuadrado. ID: " << to_string(id) << endl
				<< "Punto inicial: (" << to_string(iniciop.getX()) << "," << to_string(iniciop.getY()) << ")." << endl
				<< "Punto final: (" << to_string(finalp.getX()) << "," << to_string(finalp.getY()) << ")." << endl
				<< "Color interior: " << colorFrente->getColor() << "." << endl
				<< "Color de fondo: " << colorFondo->getColor() << "." << endl;

		return description.str();
	}

	string getType() { return "cuadrado"; }
	Point* getInitPoint() { return &iniciop; }
	int getId() { return id; }
	void setInitPoint(Point *punto)
	{
		double x = punto->getX() - iniciop.getX();
		double y = punto->getY() - iniciop.getY();
		iniciop.setX(punto->getX());
		iniciop.setY(punto->getY());
		finalp.setX(finalp.getX()+x);
		finalp.setY(finalp.getY()+y);
	}
	void setForeColor(Color *color)
	{
		delete colorFrente;
		colorFrente = color;
	}

	void setBackgroundColor(Color *color)
	{
		delete colorFondo;
		colorFondo = color;
	}

private:
	int id;
	Point iniciop;
	Point finalp;
	Color *colorFrente;
	Color *colorFondo;
};


#endif /* SHAPE_H_ */
