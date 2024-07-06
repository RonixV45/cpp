#pragma once
#include <iostream>
using namespace std;

#define OTHER_ERROR		 0x70
#define STACK_IS_EMPTY   0x01 
#define ALLOCATION_ERROR 0x02

class StackException
{
public:
	StackException(int errCode = OTHER_ERROR);
	const char* getReason(); // zwraca opis b³edu


private:
	int mErrCode;
};

inline StackException::StackException(int errCode)
{
	mErrCode = errCode;
}
inline const char* StackException::getReason() // zwraca opis b³edu
{
	switch (mErrCode)
	{
	case STACK_IS_EMPTY: return "Stack is empty!!";
	case ALLOCATION_ERROR: return "Memory allocation error";
	default: return "Other error!!";
	}
}
//============================================================================
class Stack;// zapowiedz definicji klasy

class StackItem
{

private:
	StackItem(char key, StackItem* pNext);
	char getKey() const;
	StackItem* getNext() const;

	friend class Stack;

private:
	char mKey;
	StackItem* m_pNext;
};

inline StackItem::StackItem(char key, StackItem* pNext)
{
	mKey = key; m_pNext = pNext;
}
inline char StackItem::getKey() const
{
	return mKey;
}
inline StackItem* StackItem::getNext() const
{
	return m_pNext;
}



//================================================================================
class Stack
{
public:
	Stack();
	virtual ~Stack();
public:
	void push(char key);
	char pop(); // zwraca i kasuje
	char top(); // tylko zwraca szczytowy 
	void del(); //kasuje
	bool isEmpty();



private:
	StackItem* m_pHead;

};

inline bool Stack::isEmpty()
{
	return !m_pHead;
}

