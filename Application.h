#ifndef APPLICATION_H_
#define APPLICATION_H_


class Application
{
public:
	virtual void runApp() = 0;
	virtual void shutdown() = 0;
	virtual ~Application() {}
};


#endif /* APPLICATION_H_ */



