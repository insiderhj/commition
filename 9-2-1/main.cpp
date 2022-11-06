#include <iostream>
#include <vector>
#include "animal.h"

using namespace std;

int main()
{
	char cmd;
	vector<Animal*> arr;
	string name, favoriteToy;
	int age, numStripes;

	while (1) {
		cin >> cmd;
		if (cmd == '0') break;
		if (cmd == 'z') {
			cin >> name >> age >> numStripes;
			arr.push_back(new Zebra(name, age, numStripes));
		} else if (cmd == 'c') {
			cin >> name >> age >> favoriteToy;
			arr.push_back(new Cat(name, age, favoriteToy));
		}
	}
	for (Animal *cur : arr) {
		cur->printInfo();
	}
	return 0;
}
