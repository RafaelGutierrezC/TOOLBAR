#include <iostream>
#include "Point.h"
#include "Color.h"
#include "Shape.h"
using namespace std;

int main()
{
	Shape *cuadrado1 = new Cuadrado(Point(0,1), Point(3,4), Color(1,2,3),Color(1,2,3));
	cout<<cuadrado1->pintar()<<endl;
	return 0;
}
