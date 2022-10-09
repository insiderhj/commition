#include <iostream>
#include "accounts.h"

using namespace std;

int main()
{
	char cmd;
	int id1, id2, amount;
	AccountManager manager;

	while (1)
	{
		cout << "\nJob?" << endl;
		cin >> cmd;
		if (cmd == 'Q') break;
		if (cmd == 'N') {
			manager.create();
		} else if (cmd == 'D') {
			cin >> id1 >> amount;
			manager.deposit(id1, amount);
		} else if (cmd == 'W') {
			cin >> id1 >> amount;
			manager.withdraw(id1, amount);
		} else if (cmd == 'T') {
			cin >> id1 >> id2 >> amount;
			manager.transfer(id1, id2, amount);
		}
	}
	return 0;
}
