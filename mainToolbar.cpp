#include "PaintApplication.h"


int main()
{
	Application *app = new PaintApplication();
	app->runApp();
	delete app;


	return 0;
}
