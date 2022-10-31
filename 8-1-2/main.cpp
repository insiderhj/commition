#include <iostream>
#include "rect.h"

using namespace std;

int main()
{
	string s;
	int width, height;

	while (1) {
		cin >> s;
		if (s.compare("quit") == 0) break;
		if (s.compare("nonsquare") == 0) {
			cin >> width >> height;
			NonSquare nonsquare(width, height);
			nonsquare.print();
		} else if (s.compare("square") == 0) {
			cin >> width;
			Square square(width);
			square.print();
		}
	}
	return 0;
}
