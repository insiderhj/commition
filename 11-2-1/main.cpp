#include "my_vector.h"

using namespace std;

int main()
{
	string cmd;
	MyVector a, b, res;
	int num;

	while (1)
	{
		cin >> cmd;
		if (cmd.compare("quit") == 0) break;
		if (cmd.compare("new") == 0) {
			cin >> num;
			a = MyVector(num);
			b = MyVector(num);
			cout << "enter a" << endl;
			cin >> a;
			cout << "enter b" << endl;
			cin >> b;
		}
		else if (cmd.compare("a") == 0 || cmd.compare("b") == 0) {
			if (cmd.compare("a") == 0) {
				res = a;
			} else {
				res = b;
			}
			cin >> cmd;
			cin >> cmd;
			if (cmd.compare("a") == 0) {
				res = res + a;
			} else if (cmd.compare("b") == 0) {
				res = res + b;
			} else {
				res = res + stoi(cmd);
			}
			cout << res << endl;
		}
	}
}