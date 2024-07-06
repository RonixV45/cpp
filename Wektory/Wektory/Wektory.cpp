// Wektory.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

#include "Vector.h"

int main()
{
    try
    {
        Vector v1;
        Vector v2(3);
        Vector v3(4, 1);
        Vector v4(Vector(4, 2));

        cout << "v1 = " << v1 << endl;
        cout << "v2 = " << v2 << endl;
        cout << "v3 = " << v3 << endl;
        cout << "v4 = " << v4 << endl;

        v2 = v3;
        cout << "$v2 = " << v2 << endl;

        v4 = v2 + v3;
        //v4 = v1 + v3;
        v4 = 2 + v4;
        cout << "v4 = " << v4 << endl;

        v4[1] = -100;
        cout << "v4 = " << v4 << endl;

        v4[2] = v1[3] + 1;
        cout << "v4 = " << v4 << endl;
    }
    catch (VectorException e)
    {
        cerr << "EXCEPTION: " << e.getReason() << endl;
    }
    return 0;
}


