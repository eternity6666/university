// 后缀表达式转中缀表达式
/*
#ifndef STACK_H
    #define STACK_H
    #include <stack>
#endif
*/

#ifndef MYEXPRESS_H
    #define MYEXPRESS_H
    #include "SqStack.h"
    #include <string>

int isOpMember(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 0;
    else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '\0')
        return 1;
    else
        return -1;
}

int order(char m)
{
    switch(m)
    {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        case '\0':
            return 6;
        default:
            return 7;
    }
}

int precede(char op1, char op2)
{
    int inCmpOut[7][7] = {
        { 1,  1, -1, -1, -1,  1,  1},
        { 1,  1, -1, -1, -1,  1,  1},
        { 1,  1,  1,  1, -1,  1,  1},
        { 1,  1,  1,  1, -1,  1,  1},
        {-1, -1, -1, -1, -1,  0,  0},
        { 1,  1,  1,  1,  2,  1,  1},
        {-1, -1, -1, -1, -1,  2,  0}
    };

    int i, j;
    i = order(op1);
    j = order(op2);
    return inCmpOut[i][j];
}

string transform(string mids)
{
    string suffixs = "";
    int i = 0;
    int j = 0;
    char ch = mids[0];
    // cout << mids << endl;
    SqStack<char> s;
    char op;
    s.push('\0');

    while(!s.isEmpty())
    {
        cout << suffixs << endl;
        // cout << 1 << endl;
        if(isOpMember(ch) == -1)
        {
            cout << " error " << endl;
            break;
        }
        else if(isOpMember(ch) == 0)
        {
            if(i > 0 && isOpMember(suffixs[i - 1]) == 1)
            {
                suffixs += ' ';
                i++;
            }
            suffixs += ch;
            i++;
        }
        else if(isOpMember(ch) == 1)
        {
            if(i > 0 && suffixs[i] != ' ')
            {
                suffixs += ' ';
                i++;
            }

            switch(ch)
            {
                case '(':
                    s.push(ch);
                    break;
                case ')':
                    s.pop(op);
                    while(op != '(')
                    {
                        suffixs += op;
                        i++;
                        suffixs += ' ';
                        i++;
                        s.pop(op);
                    }
                    --i;
                    break;
                default:
                    while(s.getTop(op))
                    {
                        if(precede(op, ch) == 1 || precede(op, ch) == 0)
                        {
                            suffixs += op;
                            i++;
                            suffixs += ' ';
                            i++;
                        }
                        else
                            break;
                        s.pop(op);
                    }
                    if(ch != '\0')
                        s.push(ch);
                    break;
            }
        }
        if(ch != '\0')
            ch = mids[++j];
    }
    suffixs[i] = '\0';
    return suffixs;
}

double caculate(double a, char ch, double b)
{
    switch(ch)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return -1;
    }
}

double evaluation(string suffixs)
{
    int i = 0;
    char ch = suffixs[i];
    double x;

    SqStack<double> s;

    double a, b;

    while(ch != '\0')
    {
        if(isOpMember(ch) == 0)
        {
            x = 0;
            while(isOpMember(ch) == 0)
            {
                x = x * 10 + (ch - '0');
                ch = suffixs[++i];
            }
            s.push(x);
        }
        else if(isOpMember(ch) == 1)
        {
            // b = s.top();
            s.pop(b);
            // a = s.top();
            s.pop(a);
            s.push(caculate(a, ch, b));
        }
        ch = suffixs[++i];
    }
    // x = s.top();
    s.pop(x);
    return x;
}
#endif

