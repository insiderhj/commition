#include <iostream>
#include "setfunc.h"

using namespace std;

std::set<int> parseSet(const std::string& str)
{
	set<int> res;
	int flag = 0;
	int negative = 0;
	string tmp;
	
	for (char c : str) {
		if (c == '-' || c >= '0' && c <= '9') {
			flag = 1;
			tmp += c;
		} else if (c == ' ' && flag) {
			res.insert(stoi(tmp));
			flag = 0;
			tmp = "";
		}
	}
	return res;
}

void printSet(const std::set<int>& s)
{
	cout << "{ ";
	for (int i : s) {
		cout << i << ' ';
	}
	cout << '}' << endl;
}

std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1)
{
	set<int> res;
	for (int i : set0) {
		if (set1.find(i) != set1.end())
			res.insert(i);
	}
	return res;
}

std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1)
{
	set<int> res = set0;
	res.insert(set1.begin(), set1.end());
	return res;
}

std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1)
{
	set<int> res;
	for (int i : set0) {
		if (set1.find(i) == set1.end())
			res.insert(i);
	}
	return res;
}
