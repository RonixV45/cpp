#pragma once

#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
	Person(string name = "", int age = 0);
	Person(const Person& p);
	virtual ~Person();

	void setPerson(string name, int age);
	void setName(string name);
	void setAge(int age);

	string getName() const;
	int getAge() const;


private:
	string mName;
	int mAge;
};


//INLINE FUNCTIONS

inline void Person::setName(string name)
{
	this->mName = name;
}
inline void Person::setAge(int age)
{
	mAge = age;
}
inline string Person::getName() const
{
	return mName;
}
inline int Person::getAge() const
{
	return mAge;
}