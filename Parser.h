#ifndef PARSER_H_
#define PARSER_H_

#include "CLI11.hpp"
#include <iostream>
#include "Point.h"
#include "LineCommandParse.h"
#include <string>
using namespace std;


class Parser
{
public:
	Parser(CLI::App *capp, LineCommandParse* lcp): cliapp{capp}, lineCP{lcp}
	{
		resetLineCP();
		setupCreate(cliapp,lineCP);
		setupList(cliapp,lineCP);
	}

	LineCommandParse* parse(string comando)
	{
		try
		{
			resetLineCP();
			cliapp->parse(comando);
		}
		catch(exception *e)
		{
			cout << "PARSE ERROR" << endl;
		}

		return lineCP;
	}

private:
	CLI::App *cliapp;
	LineCommandParse* lineCP;

	void resetLineCP()
	{
		lineCP->commandType = "NULL";
		lineCP->shapeType = "NULL";
		lineCP->iniciop = make_pair(0.0,0.0);
		lineCP->finalp = make_pair(0.0,0.0);
		lineCP->colorFrente = "verde";
		lineCP->colorFondo = "verde";
		lineCP->id = 0;
		lineCP->file = "";
	}

	void setupCreate(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *createSub = cli->add_subcommand("create","Create a Shape");

		createSub->add_option("-s", lineCP->shapeType, "Shape type")->required();
		createSub->add_option("-i", lineCP->iniciop, "X Initial Point")->required();
		createSub->add_option("-e", lineCP->finalp, "X Final Point")->required();
		createSub->add_option("-f", lineCP->colorFrente, "Front Color")->required(false);
		createSub->add_option("-b", lineCP->colorFondo, "Back Color")->required(false);

		createSub->callback(
			[lineCP]()
			{
				lineCP->commandType = "create";
			}
		);
	}


	void setupList(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *listSub = cli->add_subcommand("list","Create a Shape");

		lineCP->shapeType = "all";
		listSub->add_option("-s", lineCP->shapeType, "Shape type")->required(false);
		listSub->add_option("-i", lineCP->iniciop, "X Initial Point")->required(false);

		listSub->callback(
			[lineCP]()
			{
				lineCP->commandType = "list";
			}
		);
	}

	void setupApplyForeColor()
	{

	}
};


#endif /* PARSER_H_ */
