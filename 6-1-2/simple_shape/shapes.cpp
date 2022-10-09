#include "shapes.h"

double Circle::area()
{
	return x * x * 3.14;
}

double Circle::perimeter()
{
	return 2 * x * 3.14;
}

int Rectangle::area()
{
	return (x2 - x1) * (y1 - y2);
}

int Rectangle::perimeter()
{
	return 2 * (x2 - x1 + y1 - y2);
}
