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
		lineCP->colorFrente = "negro";
		lineCP->colorFondo = "blanco";
		lineCP->id = 0;
		lineCP->file = "";
	}

	void setupCreate(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("create","Create a Shape");

		sub->add_option("-s", lineCP->shapeType, "Shape type")->required();
		sub->add_option("-p", lineCP->iniciop, "Initial Point")->required();
		sub->add_option("-e", lineCP->finalp, "Final Point")->required();
		sub->add_option("-r", lineCP->colorFrente, "Front Color")->required(false);
		sub->add_option("-b", lineCP->colorFondo, "Back Color")->required(false);

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "create";
			}
		);
	}


	void setupList(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("list","Show list of Shapes");

		sub->add_option("-s", lineCP->shapeType, "Shape type")->required(false);
		sub->add_option("-p", lineCP->iniciop, "Initial Point")->required(false);

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "list";
			}
		);
	}

	void setupSelect(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("select","Select a Shape");

		sub->add_option("-i", lineCP->id, "Shape ID")->required();

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "select";
			}
		);
	}

	void setupSelectAll(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("selectAll","Select all Shapes");

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "selectAll";
			}
		);
	}

	void setupUnSelect(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("unselect","Unselect a Shape");

		sub->add_option("-i", lineCP->id, "Shape ID")->required();

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "unselect";
			}
		);
	}

	void setupUnSelectAll(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("unselectAll","Unselect all Shapes");

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "unselectAll";
			}
		);
	}
};


#endif /* PARSER_H_ */
