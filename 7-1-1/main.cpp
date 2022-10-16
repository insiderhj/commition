#include <iostream>
#include <string>
#include <vector>
#include "sorted.h"

using namespace std;

int isNumber(string s)
{
	for (char c : s)
		if (c < '0' || c > '9' && c != '-') return 0;
	return 1;
}

int main()
{
	SortedArray sa;
	string s;
	
	while (1) {
		cin >> s;
		if (isNumber(s) != 0) sa.AddNumber(stoi(s));
		if (s.compare("ascend") == 0) {
			for (int i : sa.GetSortedAscending())
				cout << i << ' ';
			cout << endl;
		} else if (s.compare("descend") == 0) {
			for (int i : sa.GetSortedDescending())
				cout << i << ' ';
			cout << endl;
		} else if (s.compare("max") == 0) {
			cout << sa.GetMax() << endl;
		} else if (s.compare("min") == 0) {
			cout << sa.GetMin() << endl;
		} else if (s.compare("quit") == 0) break;
	}
	return 0;
}
