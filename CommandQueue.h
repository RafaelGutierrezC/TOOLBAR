#ifndef QUEUE_STORE_H
#define QUEUE_STORE_H

#include <iostream>
#include <queue>
using namespace std;


class CommandQueue
{
public:
	CommandQueue()
	{
		//commandQueue = new queue<string>();
	}

	void pushCommand(string comando)
	{
		commandQueue.push(comando);
	}

	void popCommand()
	{
		commandQueue.pop();
	}

	string extractCommand()
	{
		return commandQueue.front();
	}

	bool isEmpty()
	{
		return commandQueue.empty();
	}

private:
	queue<string> commandQueue;
};


#endif /* QUEUE_STORE_H */
