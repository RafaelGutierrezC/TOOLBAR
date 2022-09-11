#include "ColorFactory.h"


Color* BlancoFactory::createColor()
{
	return new Blanco();
}

Color* NegroFactory::createColor()
{
	return new Negro();
}

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
