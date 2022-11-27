#include "my_container.h"

using namespace std;

int main()
{
	int count;

	cin >> count;
	MyContainer<int> *i_container = new MyContainer<int>(count);
	cin >> *i_container;
	cout << *i_container << endl;

	cin >> count;
	MyContainer<double> *d_container = new MyContainer<double>(count);
	cin >> *d_container;
	cout << *d_container << endl;

	cin >> count;
	MyContainer<string> *s_container = new MyContainer<string>(count);
	cin >> *s_container;
	cout << *s_container << endl;

	delete i_container;
	delete d_container;
	delete s_container;

	return 0;
}
