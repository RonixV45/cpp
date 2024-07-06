// Stos.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
    try 
    {
        Stack s1;
        Stack s2;

        s1.push('A');
        s1.push('B');
        s1.push('C');

        s2.push('$');

        cout << s1.pop();
        cout << s1.pop();
        cout << s1.pop() << endl;

        cout << s2.pop() << endl;
        cout << s2.pop() << endl; // wygeneruje wyjatek
    }
    catch (StackException e)
    {
        cerr << "EXCEPTION: " << e.getReason() << endl;
    }

    return 0;
}

