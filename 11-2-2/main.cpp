#include "my_vector2.h"

using namespace std;

int main()
{
	string cmd;
	MyVector2 *a = 0, *b = 0;
	int num;

	while (1)
	{
		cin >> cmd;
		if (cmd.compare("quit") == 0) break;
		if (cmd.compare("new") == 0) {
			cin >> num;
			if (a) delete a;
			if (b) delete b;
			a = new MyVector2(num);
			b = new MyVector2(num);
			cout << "enter a" << endl;
			cin >> *a;
			cout << "enter b" << endl;
			cin >> *b;
		}
		else if (cmd.compare("a") == 0) {
			cin >> cmd;
			cin >> cmd;
			if (cmd.compare("a") == 0) {
				MyVector2 res(*a + *a);
				cout << res << endl;
			} else if (cmd.compare("b") == 0) {
				MyVector2 res(*a + *b);
				cout << res << endl;
			} else {
				MyVector2 res(*a + stoi(cmd));
				cout << res << endl;
			}
		} else if (cmd.compare("b") == 0) {
			cin >> cmd;
			cin >> cmd;
			if (cmd.compare("a") == 0) {
				MyVector2 res(*b + *a);
				cout << res << endl;
			} else if (cmd.compare("b") == 0) {
				MyVector2 res(*b + *b);
				cout << res << endl;
			} else {
				MyVector2 res(*b + stoi(cmd));
				cout << res << endl;
			}
		}
	}
	if (a) delete a;
	if (b) delete b;
	return 0;
}