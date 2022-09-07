#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
	Point(double x, double y): x(x), y(y) {}
	Point(Point& punto): x{punto.x}, y{punto.y} {}

	double getX() { return x; }
	double getY() { return y; }

	void setX(double x) { this->x=x; }
	void setY(double y) { this->y=y; }

private:
	double x;
	double y;
};


#endif /* POINT_H_ */
