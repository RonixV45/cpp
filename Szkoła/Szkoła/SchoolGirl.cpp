#include "SchoolGirl.h"

SchoolGirl::SchoolGirl(string name, int age, string className) : Pupil(name,age,className)
{
	mID = "F_" + mID; // bezposredni dostep do skladowej chronionej klasy bazowej
}
void SchoolGirl::printOutFit() // virtual mozna nie pisac
{
	cout << "Bia³a bluzka, marynarka szkolna, czerowny krawat, spodnica granatowa/czarna";
}
