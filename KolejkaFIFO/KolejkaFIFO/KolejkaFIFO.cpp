// KolejkaFIFO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "QFIFO.h"

int main()
{
    QFifo* q = QFCreate();
    if (!q)
    {
        printf("Fifo creation error\n");
        return 1;
    }

    if(!QFEnqueue(q, 1))
    {
        printf("Enqueue error\n");
        return 2;
    }

    QFEnqueue(q, 2);
    QFEnqueue(q, 3);
    QFEnqueue(q, 4);
    QFEnqueue(q, 5);

    printf("%d\n", QFDequeue(q));
    printf("%d\n", QFDequeue(q));
    printf("%d\n", QFDequeue(q));
    
    QFEnqueue(q, 6);
    QFEnqueue(q, 7);
    QFEnqueue(q, 8);
        
    printf("%d\n", QFDequeue(q));
    printf("%d\n", QFDequeue(q));
    printf("%d\n", QFDequeue(q));
    

    QFRemove( &q );

    return 0;
}


