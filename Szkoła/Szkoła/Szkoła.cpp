// Szkoła.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;
#include "SchoolBoy.h"
#include "SchoolGirl.h"

void printALL(Pupil** p, int nSize);
//void printALL(Pupil* p[], int nSize);

int main()
{
    SchoolGirl g1("Nowak Agnieszka", 17, "3b");
    g1.setNote(POLSKI, 3.5);
    g1.setNote(MATEMATYKA, 4.5);
    g1.setNote(FIZYKA, 4.5);
    g1.setNote(INFORMATYKA, 5);
    g1.setNote(ANGIELSKI, 5);

    SchoolGirl g2("Bialon Katarzyna", 17, "3b");
    g2.setNote(POLSKI, 4);
    g2.setNote(MATEMATYKA, 3);
    g2.setNote(CHEMIA, 3.5);
    g2.setNote(NIEMIECKI, 4);

    SchoolGirl g3("Sobota Paulina", 18, "4b");
    g3.setNote(POLSKI, 3.5);
    g3.setNote(MATEMATYKA, 3.5);
    g3.setNote(FIZYKA, 4);
    
    SchoolBoy b1("Kowalski Piotr", 17, "3A");
    b1.setNote(MATEMATYKA, 4.5);
    b1.setNote(FIZYKA, 4);
    b1.setNote(ANGIELSKI, 4);

    SchoolBoy b2("Piotrowicz Jakub", 17, "3A");
    b2.setNote(MATEMATYKA, 4);
    b2.setNote(FIZYKA, 4);
    b2.setNote(ANGIELSKI, 4);
    b2.setNote(CHEMIA, 3);

    Pupil* p[] = { &g1,&g2,&g3,&b1,&b2 };
    printALL(p, sizeof(p) / sizeof(Pupil*));

   // Pupil pp;

    return 0;
}

void printALL(Pupil** p, int nSize)
{
    for (int i = 0; i < nSize; i++)
    {
        p[i]->calcAve();
        p[i]->printPupil();
        cout << endl;    }
}

