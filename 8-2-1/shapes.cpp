#include <iostream>
#include "shapes.h"

using namespace std;

int abs(int a)
{
	return a >= 0 ? a : -a;
}

double Square::GetArea()
{
	return _width * _width;
}

int Square::GetPerimeter()
{
	return _width * 4;
}

void Square::Draw(int canvas_width, int canvas_height)
{
	int row, col;
	cout << ' ';
	for (col = 0; col < canvas_width; col++)
		cout << col;
	cout << endl;
	for (row = 0; row < canvas_height; row++) {
		cout << row;
		for (col = 0; col < canvas_width; col++) {
			if (_top_x <= col && _top_x + _width > col
				&& _top_y <= row && _top_y + _height > row)
				cout << _brush;
			else
				cout << '.';
		}
		cout << endl;
	}
}

double Rectangle::GetArea()
{
	return _width * _height;
}

int Rectangle::GetPerimeter()
{
	return _width * 2 + _height * 2;
}

void Rectangle::Draw(int canvas_width, int canvas_height)
{
	int row, col;
	cout << ' ';
	for (col = 0; col < canvas_width; col++)
		cout << col;
	cout << endl;
	for (row = 0; row < canvas_height; row++) {
		cout << row;
		for (col = 0; col < canvas_width; col++) {
			if (_top_x <= col && _top_x + _width > col
				&& _top_y <= row && _top_y + _height > row)
				cout << _brush;
			else
				cout << '.';
		}
		cout << endl;
	}
}

double Diamond::GetArea()
{
	return (_dist * 2 + 1) * (_dist * 2 + 1) / 2.0;
}

int Diamond::GetPerimeter()
{
	return (_dist + 1) * 4;
}

void Diamond::Draw(int canvas_width, int canvas_height)
{
	int row, col;
	int cur_width = 0;
	cout << ' ';
	for (col = 0; col < canvas_width; col++)
		cout << col;
	cout << endl;
	for (row = 0; row < canvas_height; row++) {
		cout << row;
		for (col = 0; col < canvas_width; col++) {
			if (abs(col - _top_x) <= cur_width 
				&& _top_y <= row && _top_y + _dist * 2 >= row)
				cout << _brush;
			else
				cout << '.';
		}
		if (_top_y <= row) {
			if (_top_y + _dist > row)
				cur_width++;
			else
				cur_width--;
		}
		cout << endl;
	}
}
