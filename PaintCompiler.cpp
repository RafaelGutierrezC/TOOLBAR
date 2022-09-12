#include "PaintCompiler.h"


void PaintCompiler::initializeLineCommandMap()
{
	lineCommandFactories.insert(make_pair("create",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<CreateCommand>(canvas,toolbar,
				lineCP->shapeType,new Point(lineCP->iniciop.first,lineCP->iniciop.second),
				new Point(lineCP->finalp.first,lineCP->finalp.second),lineCP->colorFrente,lineCP->colorFondo);
		}
	));

	lineCommandFactories.insert(make_pair("list",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<ListCommand>(canvas,
				lineCP->shapeType,new Point(lineCP->iniciop.first,lineCP->iniciop.second));
		}
	));

	lineCommandFactories.insert(make_pair("select",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<SelectCommand>(canvas,lineCP->id);
		}
	));

	lineCommandFactories.insert(make_pair("selectAll",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<SelectAllCommand>(canvas);
		}
	));

	lineCommandFactories.insert(make_pair("unselect",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<UnSelectCommand>(canvas,lineCP->id);
		}
	));

	lineCommandFactories.insert(make_pair("unselectAll",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<UnSelectAllCommand>(canvas);
		}
	));

	lineCommandFactories.insert(make_pair("applyForeColor",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<ApplyForeColorCommand>(canvas,toolbar,lineCP->id,lineCP->colorFrente);
		}
	));

	lineCommandFactories.insert(make_pair("applyBackgroundColor",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<ApplyBackgroundColorCommand>(canvas,toolbar,lineCP->id,lineCP->colorFondo);
		}
	));

	lineCommandFactories.insert(make_pair("move",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<MoveCommand>(canvas,lineCP->id,new Point(lineCP->iniciop.first,lineCP->iniciop.second));
		}
	));

	lineCommandFactories.insert(make_pair("remove",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<RemoveCommand>(canvas,lineCP->id,new Point(lineCP->iniciop.first,lineCP->iniciop.second));
		}
	));

	/*lineCommandFactories.insert(make_pair("open",
		[=](LineCommandParse *lineCP)
		{
			return buildLineCommand<OpenCommand>(this,canvas,lineCP->file);
		}
	));*/
}
