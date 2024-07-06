#pragma once
#include "Time.h"
#include <iostream>
using namespace std;



class Time
{
private:
	int mHour;
	int mMin;
	int mSec;

public:
	Time(int h = 0, int m = 0, int s = 0);
	Time(const Time& t);
	virtual ~Time();

public:
	//settery
	void setTime(int h, int m, int s);
	void setHour(int h);
	void setMin(int m);
	void setSec(int s);

	//gettery
	int getHour() const;
	int getMin() const;
	int getSec() const;

public:
	void printTime();
	void readTime();
	//operatory we/wy

	friend istream& operator >> (istream& in, Time& t);
	friend ostream& operator << (ostream& out, const Time& t);



};

//// INLINE FUNCTIONS
inline int Time::getHour() const
{
	return mHour;
}

inline int Time::getMin() const
{
	return mMin;
}

inline int Time::getSec() const
{
	return mSec;
}

