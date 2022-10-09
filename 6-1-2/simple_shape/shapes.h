#ifndef SHAPES_H
# define SHAPES_H

class Circle {
private:
	int x, y, radius;
public:
	Circle() : x(0), y(0), radius(0) {}
	Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}
	double area();
	double perimeter();
};

class Rectangle {
private:
	int x1, y1, x2, y2;
public:
	Rectangle() : x1(0), y1(0), x2(0), y2(0) {}
	Rectangle(int x1, int y1, int x2, int y2)
		: x1(x1), y1(y1), x2(x2), y2(y2) {}
	int area();
	int perimeter();
};

#endif
