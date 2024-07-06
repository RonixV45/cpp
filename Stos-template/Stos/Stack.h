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
template <class T> class Stack;// zapowiedz definicji klasy

template <class T> class StackItem
{

private:
	StackItem<T>(T key, StackItem<T>* pNext);
	T getKey() const;
	StackItem<T>* getNext() const;

	friend class Stack<T>;

private:
	T mKey;
	StackItem<T>* m_pNext;
};

template <class T> StackItem<T>::StackItem(T key, StackItem<T>* pNext)
{
	mKey = key; m_pNext = pNext;
}
template <class T> T StackItem<T>::getKey() const
{
	return mKey;
}
template <class T> StackItem<T>* StackItem<T>::getNext() const
{
	return m_pNext;
}



//================================================================================
template <class T> class Stack
{
public:
	Stack<T>();
	virtual ~Stack<T>();
public:
	void push(T key);
	T pop(); // zwraca i kasuje
	T top(); // tylko zwraca szczytowy 
	void del(); //kasuje
	bool isEmpty();



private:
	StackItem<T>* m_pHead;

};

template <class T> bool Stack<T>::isEmpty()
{
	return !m_pHead;
}

template <class T> Stack<T>::Stack()
{
	m_pHead = nullptr;//NULL;
}
template <class T> Stack<T>::~Stack()
{
	while (!isEmpty())
		del();
}
template <class T> void Stack<T>::push(T key)
{
	StackItem<T>* p = new(nothrow) StackItem<T>(key, m_pHead);
	if (!p)
		throw StackException(ALLOCATION_ERROR);
	m_pHead = p;
}
template <class T> T Stack<T>::pop() // zwraca i kasuje
{
	if (!isEmpty())
	{
		T key = top();
		del();
		return key;
	}
	throw StackException(STACK_IS_EMPTY);
}
template <class T> T Stack<T>::top() // tylko zwraca szczytowy 
{
	if (!isEmpty())
		return m_pHead->getKey();
	throw StackException(STACK_IS_EMPTY);
	//return 0;
}
template <class T> void Stack<T>::del() //kasuje
{
	if (!isEmpty())
	{
		StackItem<T>* p = m_pHead;
		m_pHead = p->getNext();
		delete p;
	}
	else
		throw StackException(STACK_IS_EMPTY);

}

