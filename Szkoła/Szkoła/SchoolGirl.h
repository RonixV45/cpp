#pragma once
#include "Pupil.h"

class SchoolGirl : public Pupil
{
public:
	SchoolGirl(string name = "", int age = 0, string className = "");

	virtual void printOutFit(); // virtual mozna nie pisac

};

