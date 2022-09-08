#ifndef PARSER_H_
#define PARSER_H_

#include "CLI11.hpp"
#include <iostream>
#include <sstream>
#include "Point.h"
using namespace std;


struct LineCommandParse
{
	string commandType;
	string shapeType;
	Point *iniciop;
	Point *finalp;
	string colorFrente;
	string colorFondo;
	string id;
	string file;
};


class Parser
{
public:
	Parser(CLI::App *capp): cliapp{capp} {}

	LineCommandParse* buildParamsStruct(string comando)
	{
		LineCommandParse *lineCP = new LineCommandParse();
		string tipoComando;
		stringstream ss{comando};
		ss >> tipoComando;

		lineCP->commandType = tipoComando;
		lineCP->shapeType = "all";


		auto *shapeOption = cliapp->add_option("-s", lineCP->shapeType, "Shape type");
		pair<double,double> ip = make_pair(0.0,0.0);
		pair<double,double> ep = make_pair(0.0,0.0);

		auto *iniciopOption = cliapp->add_option("-i", ip, "X Initial Point");
		auto *finalpOption = cliapp->add_option("-e", ep, "X Final Point");
		auto *colorFrenteOption = cliapp->add_option("-f", lineCP->colorFrente, "Front Color");
		auto *colorFondoOption = cliapp->add_option("-b", lineCP->colorFondo, "Back Color");




		lineCP->iniciop = new Point(ip.first,ip.second);
		lineCP->finalp = new Point(ep.first,ep.second);


		requisiteModifiers.insert(make_pair("create",
			[=]()
			{
				parseCreate(shapeOption,iniciopOption,finalpOption,colorFrenteOption,colorFondoOption);
			}
		));

		requisiteModifiers.insert(make_pair("list",
					[=]()
					{
						parseList(shapeOption,iniciopOption);
					}
				));

		requisiteModifiers.insert(make_pair("applyForeColor",
			[=]()
			{
				parseApplyForeColor(shapeOption,colorFrenteOption);
			}
		));

		requisiteModifiers[tipoComando]();
		cliapp->parse(comando,true);

		return lineCP;
	}

private:
	CLI::App *cliapp;
	map<string,function<void()>> requisiteModifiers;

	void parseCreate(CLI::Option *shapeOption, CLI::Option *iniciopOption, CLI::Option *finalpOption,
			CLI::Option *colorFrenteOption, CLI::Option *colorFondoOption)
	{
		shapeOption->required();
		iniciopOption->required();
		finalpOption->required();
		colorFrenteOption->required(false);
		colorFondoOption->required(false);
	}

	void parseList(CLI::Option *shapeOption, CLI::Option *iniciopOption)
	{
		shapeOption->required(false);
		iniciopOption->required(false);
	}

	void parseApplyForeColor(CLI::Option *shapeOption, CLI::Option *colorFrenteOption)
	{
		shapeOption->required();
		colorFrenteOption->required();
	}
};


#endif /* PARSER_H_ */
