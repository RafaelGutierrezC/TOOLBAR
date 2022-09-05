#ifndef COLOR_H_
#define COLOR_H_

class Color
{
public:
	Color(int r, int g, int b): red(r), green(g), blue(b) {}

	double getRed() { return red; }
	double getGreen() { return green; }
	double getBlue() { return blue; }

	void setRed(int value){ red = value; }
	void setGreen(int value){ green = value; }
	void setBlue(int value){ blue = value; }

private:
	int red;
	int green;
	int blue;
};

#endif /* COLOR_H_ */
