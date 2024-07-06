#pragma once
#include "Date.h"
#include "Time.h"
class DateTime : public Date, public Time // klasa ³¹czna
{
public:
	DateTime(int DD = 1, int MM = 1, int YY = 1990, int hh = 0, int mm = 0, int ss = 0);
	DateTime(const DateTime& dt);

	DateTime& operator = (const DateTime& dt); // musi byc metoda klasy, 
	//musi zwracac refernecje i parametrem ma byc sta³a referecja
	// DLATEGO aby mozna bylo robic np: dt1 = dt2 = dt3 = dt4;

	void setDateTime(int DD, int MM, int YY, int hh, int mm, int ss);
	void setDateTime(const DateTime& dt);

	friend istream& operator >> (istream& in, DateTime& dt);
	friend ostream& operator << (ostream& out, const DateTime& dt);
};

