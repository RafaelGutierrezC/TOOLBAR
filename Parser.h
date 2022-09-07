#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include "Point.h"
using namespace std;


struct LineCommandParse
{
	string comando;
	string shape;
	Point *iniciop;
	Point *finalp;
	string colorFrente;
	string colorFondo;
};


class Parser
{
public:
	static LineCommandParse* buildParamsStruct(string comando)
	{
		// CREATE MOCKUP
		LineCommandParse *lineCP = new LineCommandParse();
		lineCP->comando = "create";
		lineCP->shape = "cuadrado";
		lineCP->iniciop = new Point(1.0,2.0);
		lineCP->finalp = new Point(3.0,4.0);
		lineCP->colorFrente = "rojo";
		lineCP->colorFondo = "azul";

		return lineCP;
	}
};


#endif /* PARSER_H_ */
