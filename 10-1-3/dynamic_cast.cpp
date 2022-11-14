#include <iostream>
#include <vector>

using namespace std;

class B 
{
public:
    virtual ~B() {}
};

class C : public B
{
public:
    void test_C() { std::cout << "C::test_C()" << std::endl; }
};

class D : public B
{
public:
    void test_D() { std::cout << "D::test_D()" << std::endl; }
};

int main()
{
	char cmd;
	vector<B*> arr;

	while (1) {
		cin >> cmd;
		if (cmd == '0') break;
		if (cmd == 'B')
			arr.push_back(new B);
		else if (cmd == 'C')
			arr.push_back(new C);
		else if (cmd == 'D')
			arr.push_back(new D);
	}

	for (B* b : arr) {
		C* c = dynamic_cast<C*>(b);
		D* d = dynamic_cast<D*>(b);
		if (c)
			c->test_C();
		else if (d)
			d->test_D();
		delete b;
	}
	return 0;
}
