#include "shape.h"

double Rectangle::getArea()
{
	return width * height;
}

double Triangle::getArea()
{
	return width * height * 0.5;
}
