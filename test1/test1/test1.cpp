// test1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;
#include "Date.h"
#include "Time.h"
#include "DateTime.h"

int main()
{
	DateTime dt1;
	DateTime dt2(2, 7, 2024, 22, 28, 24);
	DateTime dt3(dt2);

	cout << "dt1 = " << dt1 << endl;
	cout << "dt2 = " << dt2 << endl;
	cout << "dt3 = " << dt3 << endl;

	cout << "Podaj date i czas w formacie DD/MM/YY hh:mm:ss : ";
	cin >> dt1;
	cout << "dt1 = " << dt1 << endl;



	/*
	Date d1; // konstuktor domyślny
	Date d2(1,3,2024); // konstruktor z parametrami

	Date d3(d2);
	Date d4 = d2; // konstruktor kopiujacy

	//setDate(&d2, 20, 4, 2024);
	d2.setDate(20, 4, 2024);

	cout << "d2 = " << d2 << endl;// cout << endl;

	cout << "Podaj date w formacie dd/mm/yyyy: ";
	//d1.readDate();
	cin >> d1;
	cout << "d1 = " << d1 << endl;// cout << endl;
	cerr << "d1 = " << d1 << endl;
   
	return 0;
	*/

	Time t1;
	Time t2(21,56,22);
	Time t3(Time(21, 23, 44));

	

	cout << "t1 = " << t1 << endl;
	cout << "t2 = " << t2 << endl;
	cout << "t3 = " << t3 << endl;

	cout << "Podaj czas w formacie hh:mm:ss : ";
	cin >> t3;
	cout << "t3 = " << t3 << endl;
	

	return 0;
}


