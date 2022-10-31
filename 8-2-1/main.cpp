#include <iostream>
#include "shapes.h"

using namespace std;

int main()
{
	string s;
	int canvas_width, canvas_height, tx, ty, width, height, dist;
	char brush;

	cin >> canvas_width >> canvas_height;
	while (1) {
		cin >> s;
		if (s.compare("quit") == 0) break;
		if (s.compare("square") == 0) {
			cin >> tx >> ty >> width >> brush;
			Square square(tx, ty, width, brush);
			cout << "Area: " << square.GetArea() << endl
				<< "Perimeter: " << square.GetPerimeter() << endl;
			square.Draw(canvas_width, canvas_height);
		} else if (s.compare("rect") == 0) {
			cin >> tx >> ty >> width >> height >> brush;
			Rectangle rect(tx, ty, width, height, brush);
			cout << "Area: " << rect.GetArea() << endl
				<< "Perimeter: " << rect.GetPerimeter() << endl;
			rect.Draw(canvas_width, canvas_height);
		} else if (s.compare("diamond") == 0) {
			cin >> tx >> ty >> dist >> brush;
			Diamond diamond(tx, ty, dist, brush);
			cout << "Area: " << diamond.GetArea() << endl
				<< "Perimeter: " << diamond.GetPerimeter() << endl;
			diamond.Draw(canvas_width, canvas_height);
		}
	}
	return 0;
}
