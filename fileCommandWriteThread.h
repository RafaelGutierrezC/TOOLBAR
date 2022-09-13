#ifndef FILE_THREAD_H_
#define FILE_THREAD_H_

#include "CommandQueue.h"
#include "PubSub.h"


void fileCommandWriteThread(PubSub::VoidStringFunction closure, CommandQueue *commandQueue)//, CommandQueue *commandQueue)
{
	while(!commandQueue->isEmpty())
	{
		string commandToWrite = commandQueue->extractCommand();
		commandQueue->popCommand();
		closure(commandToWrite);
	}
}


#endif /* FILE_THREAD_H_ */
