#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m, int s)
{
	setTime(h, m, s);
}

Time::Time(const Time& t)
{
	*this = t;
}

Time::~Time()
{

}

// settery
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMin(m);
	setSec(s);
}
void Time::setHour(int h)
{
	if (h < 0 || h > 23)
	{
		cerr << "setHour: hour out of range\n";
		return;
	}
	mHour = h;
}

void Time::setMin(int m)
{
	if (m < 0 || m>59)
	{
		cerr << "setMin: minute out of range\n";
		return;
	}
	mMin = m;
}

void Time::setSec(int s)
{
	if (s < 0 || s>59)
	{
		cerr << "setSec: second out of range\n";
		return;
	}
	mSec = s;
}

void Time::printTime()
{
	cout << getHour() << ':' << getMin() << ":" << getSec();
}

void Time::readTime()
{
	int temp;
	char c;
	cin >> temp >> c;
	setHour(temp);

	cin >> temp >> c;
	setMin(temp);

	cin >> temp;
	setSec(temp);
}

istream& operator >> (istream& in, Time& t)
{
	int temp;
	char c;
	in >> temp >> c; t.setHour(temp);
	in >> temp >> c; t.setMin(temp);
	in >> temp ;	 t.setSec(temp);
	return in;
}

ostream& operator << (ostream& out,	const Time& t)
{
	out << t.getHour() << ":" << t.getMin() << ":" << t.getSec();
	return out;
}

