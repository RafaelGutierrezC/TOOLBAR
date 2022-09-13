#ifndef PUB_SUB_H
#define PUB_SUB_H

#include <iostream>
#include <functional>
using namespace std;


class PubSub
{
public:
	typedef function<void(string)> VoidStringFunction;
	virtual void emit(string channel, string comando) = 0;
	virtual VoidStringFunction on(string channel, VoidStringFunction handler) = 0;
};


#endif /* PUB_SUB_H */
