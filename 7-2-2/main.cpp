#include <iostream>
#include "setfunc.h"

using namespace std;

int main()
{
	int i;
	string s;
	string first, second;
	set<int> set0, set1;
	char op;

	while (1) {
		first = "";
		second = "";
		getline(cin, s);

		if (s.compare("0") == 0)
			break;
		for (i = 0; i < s.size(); i++) {
			first += s[i];
			if (s[i] == '}') break;
		}
		i += 2;
		op = s[i++];
		i++;
		for (; i < s.size(); i++) {
			second += s[i];
		}

		set0 = parseSet(first);
		set1 = parseSet(second);
		
		if (op == '+') {
			printSet(getUnion(set0, set1));
		} else if (op == '-') {
			printSet(getDifference(set0, set1));
		} else if (op == '*') {
			printSet(getIntersection(set0, set1));
		}
	}
	return 0;
}