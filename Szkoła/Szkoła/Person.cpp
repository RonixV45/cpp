#include "Person.h"

Person::Person(string name, int age)
{
	setPerson(name, age);
}
Person::Person(const Person& p)
{
	*this = p;
}
Person::~Person()
{

}
void Person::setPerson(string name, int age)
{
	setName(name);
	setAge(age);
}


