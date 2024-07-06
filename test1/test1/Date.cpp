#include "Date.h"
#include <iostream>

using namespace std;

//Date::Date()
//{
//	setDate(1, 1, 1990); //domyslna data
//}

Date::Date(int d,int m ,int y)
{
	setDate(d, m, y);
}

Date::Date(const Date& d)
{
	*this = d;
}

Date::~Date()
{

}


/// settery
void Date::setDate(int d, int m, int y) //Date:: - kwalifikator tzn fun setDate jest obudowana struktura Date
{
	setDay( d);
	setMonth( m);
	setYear( y);

}
void Date::setDay(int d)
{
	//powinna byæ walidacja d
	//tu tylko uproszczona
	if (d < 1 || d>31)
	{
		cerr << "setDate: day out of range\n"; 
			return;
	}
	mDay = d;

}
void Date::setMonth(int m)
{	// walidacja m 
	if (m < 1 || m>12)
	{
		cerr << "setMonth: month out of range\n";
		return;
	}
	mMonth = m;
}
void Date::setYear(int y)
{
	//walidacja y
	mYear = y;
}

void Date::printDate()
{
	///cout << "%d/%d/%d", getDay(pDate), getMonth(pDate), getYear(pDate);
	cout << getDay() << '/' << getMonth() << '/' << getYear();
}
void Date::readDate()
{
	int temp;
	char c;
	//scanf("%d/", &temp);
	cin >> temp >> c; // c czyta separator daty
	setDay(temp);

	//scanf("%d/", &temp);
	cin >> temp >> c;
	setMonth(temp);

	//scanf("%d", &temp);
	cin >> temp;
	setYear(temp);

}

istream& operator >> (istream& in, Date& d)
{
	int temp;
	char c; // do wczytywania separatora daty
	in >> temp >> c; d.setDay(temp);
	in >> temp >> c; d.setMonth(temp);
	in >> temp;		 d.setYear(temp);
	return in;
}
ostream& operator << (ostream& out, const Date& d) 
{
	out << d.getDay() << '/' << d.getMonth() << '/' << d.getYear();
	return out;
}

