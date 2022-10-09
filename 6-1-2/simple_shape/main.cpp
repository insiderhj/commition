#include <iostream>
#include "shapes.h"

using namespace std;

int main()
{
	char cmd;
	int x1, y1, x2, y2, radius;

	while (1)
	{
		cout << "\nshape?" << endl;
		cin >> cmd;
		if (cmd == 'Q') break;
		if (cmd == 'C') {
			cin >> x1 >> y1 >> radius;
			Circle circle(x1, y1, radius);
			cout << "area: " << circle.area() << ", perimeter: " << circle.perimeter() << endl;
		} else if (cmd == 'R') {
			cin >> x1 >> y1 >> x2 >> y2;
			Rectangle rectangle(x1, y1, x2, y2);
			cout << "area: " << rectangle.area() << ", perimeter: " << rectangle.perimeter() << endl;
		}
	}
	return 0;
}
