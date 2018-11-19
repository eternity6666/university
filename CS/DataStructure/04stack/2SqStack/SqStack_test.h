#include "SqStack.h"

template <typename elemtype>
void getByRand(SqStack<elemtype> &a, int display = 0)
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

template <typename elemtype>
void display(SqStack<elemtype> s)
{
    int n = s.getLength();
    if(n == 0)
    {
        cout << " 当前顺序栈为空" << endl;
        return;
    }
    else
    {
        elemtype *tmp = new elemtype[n];
        for(int i = n - 1; i >= 0; i--)
            s.pop(tmp[i]);

        for(int i = 0; i < n; i++)
        {
            cout.width(5);
            cout << tmp[i];
        }
        cout << endl;
        cout << "    ↑";
        for(int i = 0; i < 5 * (n - 1); i++)
            cout << ' ';
        cout << "  ↑" << endl;;
        cout << " base";
        for(int i = 0; i < 5 * (n - 1); i++)
            cout << ' ';
        cout << " top" << endl;
    }
}
