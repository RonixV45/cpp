#include "Stack.h"

Stack::Stack()
{
	m_pHead = nullptr;//NULL;
}
Stack::~Stack()
{
	while (!isEmpty())
		del();
}
void Stack::push(char key)
{
	StackItem* p = new(nothrow) StackItem(key, m_pHead);
	if (!p)
		throw StackException(ALLOCATION_ERROR);
	m_pHead = p;
}
char Stack::pop() // zwraca i kasuje
{
	if (!isEmpty())
	{
		char key = top();
		del();
		return key;
	}
	throw StackException(STACK_IS_EMPTY);
}
char Stack::top() // tylko zwraca szczytowy 
{
	if (!isEmpty())
		return m_pHead->getKey();
	//throw StackException(STACK_IS_EMPTY);
	return 0;
}
void Stack::del() //kasuje
{
	if (!isEmpty())
	{
		StackItem* p = m_pHead;
		m_pHead = p->getNext();
		delete p;
	}
	else
		throw StackException(STACK_IS_EMPTY);
	
}
