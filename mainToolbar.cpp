#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Shape.h"
using namespace std;

int main()
{
	Color *rojo = new Rojo();
	Shape *cuadrado1 = new Cuadrado(Point(0,1), Point(3,4), rojo, rojo);
	cout<<cuadrado1->pintar()<<endl;
	return 0;
}
