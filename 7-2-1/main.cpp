#include <iostream>
#include "message.h"

using namespace std;

int main()
{
	MessageBook mb;
	string cmd, str;
	int num;
	
	while (1) {
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			cin >> num;
			getchar();
			getline(cin, str);
			mb.AddMessage(num, str);
		} else if (cmd.compare("delete") == 0) {
			cin >> num;
			mb.DeleteMessage(num);
		} else if (cmd.compare("print") == 0) {
			cin >> num;
			cout << mb.GetMessage(num) << endl << endl;
		} else if (cmd.compare("list") == 0) {
			for (int i : mb.GetNumbers()) 
				cout << i << ": " << mb.GetMessage(i) << endl;
		} else if (cmd.compare("quit") == 0) break;
	}
	return 0;
}
