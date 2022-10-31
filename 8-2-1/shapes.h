class Shape {
public:
	Shape();
	Shape(int tx, int ty, int width, int height, char brush)
		: _top_x(tx), _top_y(ty), _width(width), _height(height), _brush(brush) {}

	double GetArea() {};
	int GetPerimeter() {};
	void Draw(int canvas_width, int canvas_height) {};

protected:
	int _top_x;
	int _top_y;
	int _width;
	int _height;
	char _brush;
};

class Square: public Shape {
public:
	Square(int tx, int ty, int len, char brush)
		: Shape(tx, ty, len, len, brush) {}
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);
};

class Rectangle: public Shape {
public:
	Rectangle(int tx, int ty, int width, int height, char brush)
		: Shape(tx, ty, width, height, brush) {}
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);
};

class Diamond: public Shape {
public:
	Diamond(int tx, int ty, int dist, char brush)
		: Shape(tx, ty, dist, dist, brush)
	{
		_dist = dist;
	}
	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);
private:
	int _dist;
};
