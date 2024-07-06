#include "DateTime.h"



DateTime::DateTime(int DD , int MM , int YY , int hh , int mm , int ss ) 
		: Date(DD,MM,YY),Time(hh,mm,ss)
{ }

DateTime::DateTime(const DateTime& dt) : Date((Date&)dt), Time((Time&)dt)
{ }

DateTime& DateTime::operator = (const DateTime& dt)
{
	(Date&)*this = (Date&)dt;
	*(Time*)this = (Time&)dt;
	//*dynamic_cast<Time*>(this) = dynamic_cast<const Time&>(dt);

	return *this; // ZAWSZE w operatorze
}

void DateTime::setDateTime(int DD, int MM, int YY, int hh, int mm, int ss)
{
	setDate(DD, MM, YY);
	setTime(hh, mm, ss);
}

void DateTime::setDateTime(const DateTime& dt)
{
	setDateTime(dt.getDay(), dt.getMonth(), dt.getYear(), dt.getHour(), dt.getMin(), dt.getSec());
}

istream& operator >> (istream& in, DateTime& dt)
{
	in >> (Date&)dt;
	in >> (Time&)dt;
	return in;
}

ostream& operator << (ostream& out, const DateTime& dt) 
{
	out << (Date&)dt << "--" << (Time&)dt;
	return out;
}
