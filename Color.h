#ifndef COLOR_H_
#define COLOR_H_

class Color
{
public:
	Color(int r, int g, int b): r(r), g(g), b(b){}

	double getR(){return r;}
	double getG(){return g;}
	double getB(){return b;}

private:
	int r;
	int g;
	int b;
};

#endif /* COLOR_H_ */
