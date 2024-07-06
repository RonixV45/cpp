#ifndef QFIFO_H
#define QFIFO_H

#include <stdio.h>
#include <stdlib.h>

//zdefiniowac typ dla elementu listy (kolejki)

typedef struct tagQFifoItem
{
	int info; // info przechowywane w kolejce 
	tagQFifoItem* pNext; // wskaznik na kolejny element listy (kolejki)
}QFifoItem;

//zdefiniowac typ dla kolejki

typedef struct
{
	QFifoItem* pHead; // wsk do pierwszego elementu w kolejce - do pobrania elementu z kolejki
	QFifoItem* pTail; // wsk do ostatniego elementu w kolejce - do wstawiania elementu do kolejki


}QFifo;

// zdefiniowac naglowki funkcji dzialajacych na kolejce

QFifo* QFCreate();				//kreowanie kolejki FIFO    //QF === Queue Fifo
int QFEmpty(QFifo* q);			// sprawdza czy kolejka nie istnieje i czy jest pusta
int QFEnqueue(QFifo* q, int x); // wstawianie do kolejki q elementu x, zwraca 0 jesli blad i 1 jesli OK
int QFDequeue(QFifo* q);		// usuwanie z kolejki pierwszego i zwrocenie, INT_MIN gdy blad
void QFClear(QFifo* q);			// czysci kolejke
void QFRemove(QFifo** q);		// usuwa kolejke i ja zeruje(wstawia NULL do wskaznika)
 


#endif // !QFIFO_H

