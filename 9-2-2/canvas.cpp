#include <iostream>
#include "canvas.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col) : width(row), height(col)
{
	canvas = new char*[height];
	for (int r = 0; r < height; r++) {
		canvas[r] = new char[width];
		for (int c = 0; c < width; c++)
			canvas[r][c] = '.';
	}
}

Canvas::~Canvas()
{
	for (int row = 0; row < height; row++) {
		delete[] canvas[row];
	}
	delete[] canvas;
}

void Canvas::Resize(size_t w, size_t h)
{
	char **temp;
	
	temp = new char*[h];
	for (int row = 0; row < h; row++) {
		temp[row] = new char[w];
		for (int col = 0; col < w; col++) {
			temp[row][col] = '.';
		}
	}

	for (int row = 0; row < height; row++) {
		delete[] canvas[row];
	}
	delete[] canvas;

	width = w;
	height = h;
	canvas = temp;
}

bool Canvas::DrawPixel(int row, int col, char brush)
{
	if (row < 0 || row >= height || col < 0 || col >= width)
		return false;
	canvas[row][col] = brush;
	return true;
}

void Canvas::Print()
{
	int row, col;

	cout << ' ';
	for (col = 0; col < width; col++)
		cout << col;
	cout << endl;
	for (row = 0; row < height; row++) {
		cout << row;
		for (col = 0; col < width; col++)
			cout << canvas[row][col];
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			canvas[row][col] = '.';
		}
	}
}

void Rectangle::Draw(Canvas *canvas)
{
	for (int row = y; row < y + height; row++) {
		for (int col = x; col < x + width; col++)
			canvas->DrawPixel(row, col, brush);
	}
}

void Rectangle::GetInfo()
{
	cout << "rect " << x << ' ' << y << ' '
		<< width << ' ' << height << ' ' << brush << endl;
}

void UpTriangle::Draw(Canvas *canvas)
{
	size_t cur_dist = 1;
	for (int row = y; row < y + height; row++) {
		for (int col = x - cur_dist + 1; col < x + cur_dist; col++)
			canvas->DrawPixel(row, col, brush);
		cur_dist++;
	}
}

void UpTriangle::GetInfo()
{
	cout << "tri_up " << x << ' ' << y << ' '
		<< height << ' ' << brush << endl;
}

void DownTriangle::Draw(Canvas *canvas)
{
	size_t cur_dist = height;
	for (int row = y - height + 1; row <= y; row++) {
		for (int col = x - cur_dist + 1; col < x + cur_dist; col++)
			canvas->DrawPixel(row, col, brush);
		cur_dist--;
	}
}

void DownTriangle::GetInfo()
{
	cout << "tri_down " << x << ' ' << y << ' '
		<< height << ' ' << brush << endl;
}

void Diamond::Draw(Canvas *canvas)
{
	int row, col;
	size_t cur_dist = 1;
	for (row = y; row <= y + dist; row++) {
		for (col = x - cur_dist + 1; col < x + cur_dist; col++)
			canvas->DrawPixel(row, col, brush);
		cur_dist++;
	}
	cur_dist -= 2;
	for (; row <= y + dist * 2 + 1; row++) {
		for (col = x - cur_dist + 1; col < x + cur_dist; col++)
			canvas->DrawPixel(row, col, brush);
		cur_dist--;
	}
}

void Diamond::GetInfo()
{
	cout << "diamond " << x << ' ' << y << ' '
		<< dist << ' ' << brush << endl;
}
