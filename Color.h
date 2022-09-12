#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
using namespace std;

class Color
{
public:
	Color(){}
	virtual string getColor() = 0;
	virtual ~Color() {}

};


class Blanco: public Color
{
public:
	string getColor() { return "Blanco"; }
	virtual ~Blanco() {}
};


class Negro: public Color
{
public:
	string getColor() { return "Negro"; }
	virtual ~Negro() {}
};


class Rojo: public Color
{
public:
	string getColor() { return "Rojo"; }
	virtual ~Rojo() {}
};


class Verde: public Color
{
public:
	string getColor() { return "Verde"; }
	virtual ~Verde() {}
};


class Azul: public Color
{
public:
	string getColor() { return "Azul"; }
	virtual ~Azul() {}
};

#endif /* COLOR_H_ */
