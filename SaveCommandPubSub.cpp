#include "SaveCommandPubSub.h"
#include "writeInFile.h"

void SaveCommandPubSub::emit(string channel, string comando)
{
	auto foundChannel = suscriptors.find(channel);
	if(foundChannel != suscriptors.end())
	{
		auto handlerVector = foundChannel->second;
		for(auto handlerVectorIter = handlerVector.begin(); handlerVectorIter != handlerVector.end(); handlerVectorIter++)
		{
			(*handlerVectorIter)(comando);
		}
	}
}

PubSub::VoidStringFunction SaveCommandPubSub::on(string channel, VoidStringFunction handler)
{
	suscriptors[channel].push_back(handler);

	return
		[](string comando)
		{
			writeInFile(comando);
		};
}
