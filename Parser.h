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
		capp->require_subcommand(1,1);
		setupCreate(cliapp,lineCP);
		setupList(cliapp,lineCP);
		setupSelect(cliapp,lineCP);
		setupSelectAll(cliapp,lineCP);
		setupUnselect(cliapp,lineCP);
		setupUnselectAll(cliapp,lineCP);
		setupApplyForeColor(cliapp,lineCP);
		setupApplyBackgroundColor(cliapp,lineCP);
		setupMove(cliapp,lineCP);
		setupRemove(cliapp,lineCP);
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

	void setupUnselect(CLI::App *cli, LineCommandParse *lineCP)
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

	void setupUnselectAll(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("unselectAll","Unselect all Shapes");

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "unselectAll";
			}
		);
	}

	void setupApplyForeColor(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("applyForeColor","Apply foreground color to a Shape");

		sub->add_option("-i", lineCP->id, "Shape ID")->required();
		sub->add_option("-r", lineCP->colorFrente, "Front Color")->required();

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "applyForeColor";
			}
		);
	}

	void setupApplyBackgroundColor(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("applyBackgroundColor","Apply background color to a Shape");

		sub->add_option("-i", lineCP->id, "Shape ID")->required();
		sub->add_option("-b", lineCP->colorFondo, "Background Color")->required();

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "applyBackgroundColor";
			}
		);
	}

	void setupMove(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("move","Move a Shape");

		sub->add_option("-i", lineCP->id, "Shape ID")->required();
		sub->add_option("-p", lineCP->iniciop, "Initial Point")->required();

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "move";
			}
		);
	}

	void setupRemove(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("remove","Remove a(some) Shape(s)");
		sub->require_option(1,2);

		sub->add_option("-i", lineCP->id, "Shape ID")->required(false);
		sub->add_option("-p", lineCP->iniciop, "Initial Point")->required(false);

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "remove";
			}
		);
	}

	void setupOpen(CLI::App *cli, LineCommandParse *lineCP)
	{
		auto *sub = cli->add_subcommand("open","Open a file");

		sub->add_option("-f", lineCP->file, "File")->required();

		sub->callback(
			[lineCP]()
			{
				lineCP->commandType = "open";
			}
		);
	}
};


#endif /* PARSER_H_ */
