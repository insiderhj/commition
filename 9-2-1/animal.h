#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
using namespace std;

class Animal {
public:
	string name;
	int age;
	Animal(string _name, int _age);
	virtual void printInfo();
};

class Zebra: public Animal {
public:
	int numStripes;
	Zebra(string _name, int _age, int _numStripes);
	void printInfo();
};

class Cat: public Animal {
public:
	string favoriteToy;
	Cat(string _name, int _age, string _favoriteToy);
	void printInfo();
};

#endif
