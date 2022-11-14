#ifndef CLOCKS_H
# define CLOCKS_H
# include "clock_time.h"

class Clock {
protected:
	ClockTime _clockTime;
	double _driftPerSecond;
	double _totalDrift;
public:
	Clock(int hour, int minute, int second, double driftPerSecond);
	void reset();
	void tick();
	virtual void displayTime() = 0;
};

class NaturalClock: public Clock {
public:
	NaturalClock(int hour, int minute, int second, double driftPerSecond)
		: Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class SundialClock: public NaturalClock {
public:
	SundialClock(int hours, int minutes, int seconds)
		: NaturalClock(hours, minutes, seconds, 0.0) {}
	void displayTime();
};

class MechanicalClock: public Clock {
public:
	MechanicalClock(int hour, int minute, int second, double driftPerSecond)
		: Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class CuckooClock: public MechanicalClock {
public:
	CuckooClock(int hours, int minutes, int seconds)
		: MechanicalClock(hours, minutes, seconds, 0.0) {}
	void displayTime();
};

class GrandFatherClock: public MechanicalClock {
public:
	GrandFatherClock(int hours, int minutes, int seconds)
		: MechanicalClock(hours, minutes, seconds, 0.000694444) {}
	void displayTime();
};

class DigitalClock: public Clock {
public:
	DigitalClock(int hour, int minute, int second, double driftPerSecond)
		: Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class WristClock: public DigitalClock {
public:
	WristClock(int hours, int minutes, int seconds)
		: DigitalClock(hours, minutes, seconds, 0.000347222) {}
	void displayTime();
};

class QuantumClock: public Clock {
public:
	QuantumClock(int hour, int minute, int second, double driftPerSecond)
		: Clock(hour, minute, second, driftPerSecond) {}
	virtual void displayTime() = 0;
};

class AtomicClock: public QuantumClock {
public:
	AtomicClock(int hours, int minutes, int seconds)
		: QuantumClock(hours, minutes, seconds, 0.000034722) {}
	void displayTime();
};

#endif
