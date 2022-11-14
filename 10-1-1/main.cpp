#include <iostream>
#include <vector>
#include "shape.h"

using namespace std;

int main()
{
	char cmd;
	double width, height;
	vector<Shape*> arr;

	while (1) {
		cin >> cmd;
		if (cmd == '0') break;
		if (cmd == 'r') {
			cin >> width >> height;
			arr.push_back(new Rectangle(width, height));
		} else if (cmd == 't') {
			cin >> width >> height;
			arr.push_back(new Triangle(width, height));
		}
	}

	for (Shape *shape : arr) {
		cout << shape->getArea() << endl;
		delete shape;
	}
	return 0;
}
