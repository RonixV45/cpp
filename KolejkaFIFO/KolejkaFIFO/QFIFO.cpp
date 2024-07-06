#include "QFIFO.h"


QFifo* QFCreate()
{
	return(QFifo*)calloc(1, sizeof(QFifo)); // calloc zeruje pamiec => pHead i pTail sa NULL-ami
}
int QFEmpty(QFifo* q)			
{
	return !q || !(q->pHead);
}
int QFEnqueue(QFifo* q, int x)
{
	if (!q)
	{
		printf("QFEnqueue: missing queue\n");
		return 0; // blad
	}
	QFifoItem* p = (QFifoItem*)calloc(1, sizeof(QFifoItem));
	if (!p)
	{
		printf("QFEnqueue: memory allocation error\n");
		return 0; // blad
	}
	// poniewaz uzyto calloc to p->pNext jest juz NULL
	// wstawiam info do nowego elementu kolejki 
	p->info = x;

	if (QFEmpty(q))
		q->pHead = p;
	else
		q->pTail->pNext = p;

	q->pTail = p;

	return 1; // ok dowiazalo sie do kolejki 
}
int QFDequeue(QFifo* q)
{
	if (!q)
	{
		printf("QFDequeue: missing queue\n");
		return INT_MIN; // blad
	}
	int info = q->pHead->info; // zapamietanie info z pierwszego elementu kolejki

	// usuniecie pierwszego elementu z kolejki 
	QFifoItem* p = q->pHead; // zlapanie wsk p pierwszego elmentu listy
	q->pHead = p->pNext; // lub q->pHead->pNext // przekazanie wsk na poczatek listy na kolejny element
	free(p); // usuniecie pierwszego elementu

	if (QFEmpty(q))
		q->pTail = NULL;

	return info;
}
void QFClear(QFifo* q)
{
	if (!q)
	{
		printf("QFClear: Missing queue!\n");
		return;
	}
	while (!QFEmpty(q))
		QFDequeue(q);
}
void QFRemove(QFifo** q)
{
	if(!q || !*q)
	{
		printf("QFRemove: Missing queue!\n");
		return;
	}
	QFClear(*q);
	free(*q);
	*q = NULL;
}