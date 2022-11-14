#include <iostream>
#include <vector>
#include "clocks.h"

using namespace std;

int main()
{
	int ticks;
	vector<Clock*> clocks;
	
	clocks.push_back(new SundialClock(0, 0, 0));
	clocks.push_back(new CuckooClock(0, 0, 0));
	clocks.push_back(new GrandFatherClock(0, 0, 0));
	clocks.push_back(new WristClock(0, 0, 0));
	clocks.push_back(new AtomicClock(0, 0, 0));

	cin >> ticks;

	cout << "Reported clock times after resetting:" << endl;
	for (Clock* clock : clocks) {
		clock->reset();
		clock->displayTime();
	}
	cout << "\nRunning the clocks...\n\n"
		<< "Reported clock times after running:" << endl;
	for (Clock* clock : clocks) {
		for (int i = 0; i < ticks; i++)
			clock->tick();
		clock->displayTime();
	}

	return 0;
}
