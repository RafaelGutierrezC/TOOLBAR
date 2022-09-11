#ifndef LINECOMMAND_PARSE_H_
#define LINECOMMAND_PARSE_H_

#include <iostream>
#include "Point.h"
using namespace std;


struct LineCommandParse
{
	string commandType;
	string shapeType;
	pair<double,double> iniciop;
	pair<double,double> finalp;
	string colorFrente;
	string colorFondo;
	int id;
	string file;
};
#endif /* LINECOMMAND_PARSE_H_ */
