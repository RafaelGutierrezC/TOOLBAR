#include "ColorFactory.h"

Color* RojoFactory::createColor()
{
	return new Rojo();
}

Color* VerdeFactory::createColor()
{
	return new Verde();
}

Color* AzulFactory::createColor()
{
	return new Azul();
}
