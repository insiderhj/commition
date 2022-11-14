#include <iostream>
#include "clocks.h"

using namespace std;

Clock::Clock(int hour, int minute, int second, double driftPerSecond)
{
	_clockTime = ClockTime(hour, minute, second, 1);
	_driftPerSecond = driftPerSecond;
	_totalDrift = 0;
}

void Clock::reset()
{
	_clockTime.reset();
}

void Clock::tick()
{
	_clockTime.increment();
	_totalDrift += _driftPerSecond;
}

void SundialClock::displayTime()
{
	cout << "SundialClock ";
	Clock::_clockTime.display();
	cout << ", total drift: " << Clock::_totalDrift << endl;
}

void CuckooClock::displayTime()
{
	cout << "CuckooClock ";
	Clock::_clockTime.display();
	cout << ", total drift: " << Clock::_totalDrift << endl;
}

void GrandFatherClock::displayTime()
{
	cout << "GrandFatherClock ";
	Clock::_clockTime.display();
	cout << ", total drift: " << Clock::_totalDrift << endl;
}

void WristClock::displayTime()
{
	cout << "WristClock ";
	Clock::_clockTime.display();
	cout << ", total drift: " << Clock::_totalDrift << endl;
}

void AtomicClock::displayTime()
{
	cout << "AtomicClock ";
	Clock::_clockTime.display();
	cout << ", total drift: " << Clock::_totalDrift << endl;
}
