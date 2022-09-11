#ifndef COMPILER_MAP_INITIALIZER_H_
#define COMPILER_MAP_INITIALIZER_H_

#include <map>
#include <functional>
#include "LineCommand.h"
#include "LineCommandParse.h"


class CompilerMapInitializer
{
public:
	static void initializeLineCommandMap(Canvas *canvas, Toolbar *toolbar, map<string,function<LineCommand*(LineCommandParse*)>>* lineCommandFactories)
	{
		lineCommandFactories->insert(make_pair("create",
			[=](LineCommandParse *lineCP)
			{
				return buildLineCommand<CreateCommand>(canvas,toolbar,
						lineCP->shapeType,new Point(lineCP->iniciop.first,lineCP->iniciop.second),
						new Point(lineCP->finalp.first,lineCP->finalp.second),lineCP->colorFrente,lineCP->colorFondo);
			}
		));

		lineCommandFactories->insert(make_pair("list",
			[=](LineCommandParse *lineCP)
			{
				return buildLineCommand<ListCommand>(canvas,toolbar,
						lineCP->shapeType,new Point(lineCP->iniciop.first,lineCP->iniciop.second));
			}
		));

		lineCommandFactories->insert(make_pair("select",
			[=](LineCommandParse *lineCP)
			{
				return buildLineCommand<SelectCommand>(canvas,toolbar,lineCP->id);
			}
		));

		lineCommandFactories->insert(make_pair("selectAll",
			[=](LineCommandParse *lineCP)
			{
				return buildLineCommand<SelectAllCommand>(canvas,toolbar);
			}
		));

		lineCommandFactories->insert(make_pair("unselect",
			[=](LineCommandParse *lineCP)
			{
				return buildLineCommand<UnSelectCommand>(canvas,toolbar,lineCP->id);
			}
		));

		lineCommandFactories->insert(make_pair("unselectAll",
			[=](LineCommandParse *lineCP)
			{
				return buildLineCommand<UnSelectAllCommand>(canvas,toolbar);
			}
		));

	}
};


#endif /* COMPILER_MAP_INITIALIZER_H_ */
