#include <unistd.h>

class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();

	// Change this canvas size to w x h. Preserve already existing shapes on the canvas.
	void Resize(size_t w, size_t h);

	// Dot with the brush at (x,y). If (x,y) is outside the canvas, just ignore it.
	bool DrawPixel(int x, int y, char brush);

	//Print out the canvas
	void Print();

	// Erase all (initialize with '.')
	void Clear();
private:
	// Define data member to save drawn shapes (note the resize function)
	size_t width, height;
	char **canvas;
};

class Shape {
public:
	Shape(size_t x, size_t y, char brush)
		: x(x), y(y), brush(brush) {}
	virtual ~Shape() {}
	virtual void Draw(Canvas* canvas) {}
	virtual void GetInfo() {}
protected:
	// Define common properties of shapes
	size_t x, y;
	char brush;
};

class Rectangle : public Shape { 
public:
	/* Define required members */
	size_t width, height;
	Rectangle(size_t x, size_t y, size_t width, size_t height, char brush)
		: Shape(x, y, brush), width(width), height(height) {}
	void Draw(Canvas *canvas);
	void GetInfo();
};

class UpTriangle : public Shape {
public:
	/* Define required members */
	size_t height;
	UpTriangle(size_t x, size_t y, size_t height, char brush)
		: Shape(x, y, brush), height(height) {}
	void Draw(Canvas *canvas);
	void GetInfo();
};

class DownTriangle : public Shape {
public:
	/* Define required members */
	size_t height;
	DownTriangle(size_t x, size_t y, size_t height, char brush)
		: Shape(x, y, brush), height(height) {}
	void Draw(Canvas *canvas);
	void GetInfo();
};

class Diamond : public Shape {
public:
	/* Define required members */
	size_t dist;
	Diamond(size_t x, size_t y, size_t dist, char brush)
		: Shape(x, y, brush), dist(dist) {}
	void Draw(Canvas *canvas);
	void GetInfo();
};
