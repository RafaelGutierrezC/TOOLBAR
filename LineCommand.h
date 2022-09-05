#ifndef LINE_COMMAND_H_
#define LINE_COMMAND_H_


class LineCommand
{
public:
	virtual void execute() = 0;
};


class CreateCommand: public LineCommand
{
public:
	void execute();
};


#endif /* LINE_COMMAND_H_ */
