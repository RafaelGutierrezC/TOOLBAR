#ifndef COMPILER_H_
#define COMPILER_H_

#include <iostream>
using namespace std;

class Compiler
{
public:
	virtual void compile(string comando) = 0;
	virtual ~Compiler() {}
};


#endif /* OMPILER_H_ */
