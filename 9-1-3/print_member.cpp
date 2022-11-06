#include <iostream>
#include <vector>

using namespace std;

class A {
private:
	int *memberA;
public:
	A(int a) {
		memberA = new int(a);
		cout << "new memberA" << endl;
	}
	virtual ~A() {
		delete memberA;
		cout << "delete memberA" << endl;
	}
	virtual void print() {
		cout << "*memberA " << *memberA << endl;
	}
};

class B: public A {
private:
	double *memberB;
public:
	B(double b) : A(1) {
		memberB = new double(b);
		cout << "new memberB" << endl;
	}
	virtual ~B() {
		delete memberB;
		cout << "delete memberB" << endl;
	}
	virtual void print() {
		A::print();
		cout << "*memberB " << *memberB << endl;
	}
};

class C: public B {
private:
	string *memberC;
public:
	C(string c) : B(1.1) {
		memberC = new string(c);
		cout << "new memberC" << endl;
	}
	~C() {
		delete memberC;
		cout << "delete memberC" << endl;
	}
	void print() {
		B::print();
		cout << "*memberC " << *memberC << endl;
	}
};

int main()
{
	int aa;
	double bb;
	string cc;

	cin >> aa >> bb >> cc;

	A *a = new A(aa);
	B *b = new B(bb);
	C *c = new C(cc);

	vector<A*> arr;

	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);

	for (A *cur : arr) {
		cur->print();
	}
	for (A *cur : arr) {
		delete cur;
	}
	return 0;
}
