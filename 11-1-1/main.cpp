#include "my_string.h"

using namespace std;

int main()
{
	string cmd;
	MyString a, b, res;
	int count;

	while (1)
	{
		cin >> cmd;
		if (cmd.compare("quit") == 0) break;
		if (cmd.compare("new") == 0) {
			cout << "enter a" << endl;
			cin >> a;
			cout << "enter b" << endl;
			cin >> b;
		}
		else if (cmd.compare("a") == 0) {
			cin >> cmd;
			if (cmd.compare("*") == 0) {
				cin >> count;
				res = a * count;
				cout << res << endl;
			}
			else if (cmd.compare("+") == 0) {
				cin >> cmd;
				if (cmd.compare("a") == 0) {
					res = a + a;
					cout << res << endl;
				} else if (cmd.compare("b") == 0) {
					res = a + b;
					cout << res << endl;
				}
			}
		}
		else if (cmd.compare("b") == 0) {
			cin >> cmd;
			if (cmd.compare("*") == 0) {
				cin >> count;
				res = b * count;
				cout << res << endl;
			}
			else if (cmd.compare("+") == 0) {
				cin >> cmd;
				if (cmd.compare("a") == 0) {
					res = b + a;
					cout << res << endl;
				} else if (cmd.compare("b") == 0) {
					res = b + b;
					cout << res << endl;
				}
			}
		}
	}
}