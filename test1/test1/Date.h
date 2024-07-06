#pragma once
#include "Date.h"
#include <iostream>
using namespace std;
/*
 struct Date // struktura TO KLASA z calym interfejsem PUBLICZNYM
{
	int mDay;	// m - "member"
	int mMonth;
	int mYear;

	/// settery
	void setDate( int d, int m, int y);
	void setDay( int d);
	void setMonth( int m);
	void setYear( int y);

	///gettery
	int getDay();
	int getMonth();
	int getYear();

	void printDate();
	void readDate();

} ; // Nazwa typu stukturalnego
*/

class Date
{
	//interfejs prywatny
private:
	int mDay;	// m - "member"
	int mMonth;
	int mYear;

public: //construction/destrutcion
	//Date(); // konstruktor domyœlny - MUSI BYÆ jesli bedziemy tworzyc tablice obiektów tego typu
	Date(int d=1, int m=1, int y=1990);// konstruktor z parametrami domyslnymi
	Date(const Date& d); //konstruktor kopiujacy
	virtual ~Date(); // wirtualny destruktor

//interfejs publiczny
public:
	/// settery
	void setDate(int d, int m, int y);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	///gettery
	int getDay() const;
	int getMonth() const;
	int getYear() const;
public:
	void printDate();
	void readDate();
	// operatory we/wy
	friend istream& operator >> (istream& in, Date& d);
	friend ostream& operator << (ostream& out, const Date& d);

};

//==== INLINE FUNCTIONS
//gettery
inline int Date::getDay() const
{
	return mDay;
}
inline int Date::getMonth() const
{
	return mMonth;
}
inline int Date::getYear() const
{
	return mYear;
}