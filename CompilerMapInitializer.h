#ifndef COMPILER_MAP_INITIALIZER_H_
#define COMPILER_MAP_INITIALIZER_H_

#include <map>
#include <functional>
#include "Parser.h"
#include "LineCommand.h"


class CompilerMapInitializer
{
public:
	static void initializeLineCommandMap(Canvas *canvas, Toolbar *toolbar,
			map<string,function<LineCommand*()>>& lineCommandFactories, LineCommandParse *lineCP)
	{
		lineCommandFactories.insert(make_pair("create",
				[&]()
				{
					return buildLineCommand<CreateCommand>(canvas,toolbar,
							lineCP->shape,lineCP->iniciop,lineCP->finalp,lineCP->colorFrente,lineCP->colorFondo);
				}
		));

	}
};


#endif /* COMPILER_MAP_INITIALIZER_H_ */
