#ifndef SAVE_COMMAND_PUB_SUB_H
#define SAVE_COMMAND_PUB_SUB_H

#include <vector>
#include <map>
#include <algorithm>
#include "PubSub.h"
#include "CommandQueue.h"
//#include "writeInFile.h"


class SaveCommandPubSub: public PubSub
{
public:
	SaveCommandPubSub() {}
	virtual ~SaveCommandPubSub() {}
	void emit(string channel, string comando);
	VoidStringFunction on(string channel, VoidStringFunction handler);

private:
	map<string,vector<VoidStringFunction>> suscriptors;
};


#endif // SAVE_COMMAND_PUB_SUB_H
