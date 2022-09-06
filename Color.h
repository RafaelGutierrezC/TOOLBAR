#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
using namespace std;

class Color
{
public:
	Color(){}
	virtual string getColor()=0;

};

class Rojo: public Color{
public:
	string getColor(){return "Rojo";}
};

class Verde: public Color{
public:
	string getColor(){return "Verde";}
};

class Azul: public Color{
public:
	string getColor(){return "Azul";}
};

#endif /* COLOR_H_ */
