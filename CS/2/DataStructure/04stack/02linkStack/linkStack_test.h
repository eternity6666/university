#ifndef LINKSTACK_TEST_H
    #define LINKSTACK_TEST_H

#include "linkStack.h"

template <typename elemtype>
void display(linkStack<elemtype> a)
{
    int n = a.getLength();
    if(n)
    {
        // cout << 1 << endl;
        for(int i = 0; i < n; i++)
        {
            elemtype e;
            a.pop(e);
            cout.width(5);
            cout.fill(' ');
            cout << e;
            if(i + 1 != n)
                cout << "→";
        }
        cout << endl;
        cout << "   ↑" << endl;
        cout << "  top" << endl;
    }
    else
        return ;
}

template <typename elemtype>
void getByRand(linkStack<elemtype> &a, int display = 0)
{
    a.clear();
    int n = rand() % 8;
    int array[10];
    for(int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        cout.width(5);
        cout.fill(' ');
        if(display)
            cout << array[i];
        a.push(array[i]);
    }
    if(display)
        cout << endl;
}
#endif

