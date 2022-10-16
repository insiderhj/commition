#include <iostream>
#include <string>
#include <vector>
#include "intset.h"

using namespace std;

int main()
{
	IntegerSet is;
	string s;
	int num;
	
	while (1) {
		cin >> s;
		if (s.compare("add") == 0) {
			cin >> num;
			is.AddNumber(num);
			for(int i : is.GetAll())
				cout << i << ' ';
			cout << endl;
		} else if (s.compare("del") == 0) {
			cin >> num;
			is.DeleteNumber(num);
			for (int i : is.GetAll())
				cout << i << ' ';
			cout << endl;
		} else if (s.compare("get") == 0) {
			cin >> num;
			cout << is.GetItem(num) << endl;
		} else if (s.compare("quit") == 0) break;
	}
	return 0;
}
