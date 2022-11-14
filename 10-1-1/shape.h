#ifndef SHAPE_H
# define SHAPE_H

class Shape {
protected:
	double width, height;
public:
	Shape(double width, double height) : width(width), height(height) {}
	virtual double getArea() = 0;
};

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : Shape(width, height) {}
	double getArea();
};

class Triangle : public Shape {
public:
	Triangle(double width, double height) : Shape(width, height) {}
	double getArea();
};

#endif
