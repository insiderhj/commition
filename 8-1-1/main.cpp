#include <iostream>
#include "number.h"

using namespace std;

int main()
{
	string s;
	int n;

	while (1) {
		cin >> s;
		if (s.compare("quit") == 0) break;
		cin >> n;
		if (s.compare("number") == 0) {
			Number number;
			number.setNumber(n);
			cout << "getNumber(): " << number.getNumber() << endl;
		} else if (s.compare("square") == 0) {
			Square square;
			square.setNumber(n);
			cout << "getNumber(): " << square.getNumber() << endl
				<< "getSquare(): " << square.getSquare() << endl;
		} else if (s.compare("cube") == 0) {
			Cube cube;
			cube.setNumber(n);
			cout << "getNumber(): " << cube.getNumber() << endl
				<< "getSquare(): " << cube.getSquare() << endl
				<< "getCube(): " << cube.getCube() << endl;
		}
	}
	return 0;
}
