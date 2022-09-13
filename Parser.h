#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <string>
#include "LineCommandParse.h"
using namespace std;

class Parser
{
public:
	virtual LineCommandParse* parse(string comando) = 0;
	virtual ~Parser() {}
};


#endif /* PARSER_H */
