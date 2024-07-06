#include "SchoolBoy.h"

SchoolBoy::SchoolBoy(string name, int age, string className) : Pupil(name, age, className)
{
	mID = "M_" + mID; // bezposredni dostep do skladowej chronionej klasy bazowej
}
void SchoolBoy::printOutFit() // virtual mozna nie pisac
{
	cout << "Bia³a koszula, marynarka szkolna, czerowny krawat, spodnie granatowa/czarne";
}