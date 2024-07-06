#pragma once

#include "Person.h"

enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };
#define SUBJECTSNO 7

class Pupil : public Person
{
public:
	Pupil(string name = "", int age = 0, string className = "");
	Pupil(const Pupil& pu);

	void setClassName(string className);
	string getClassName() const;
	string getID() const;
	double getAve() const;
	
	void clearNotes();
	void setNote(Subjects sub, double note);
	double calcAve();
	void printPupil();
	//virtual void printOutFit() { cerr << "ERROR\n"; }
	virtual void printOutFit() = 0; // jest to tzw metoda czysta ==> klasa tez jest czysta
	//NIE WOLNO zdefiniowac obiektu tej klasy

protected:
	string mID;

private:
	static int mBaseID; // wspolny atrybut dla kazdego obiektu tej klasy

	string mClassName;
	double mAve;
	double mNotes[SUBJECTSNO];
};


///INLINE FUNCTIONS

inline void Pupil::setClassName(string className)
{
	mClassName = className;
}
inline string Pupil::getClassName() const
{
	return mClassName;
}
inline string Pupil::getID() const
{
	return mID;
}
inline double Pupil::getAve() const
{
	return mAve;

}