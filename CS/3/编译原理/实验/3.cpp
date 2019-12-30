#include <iostream>
using namespace std;

int table[6][6] = {
    1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, 1, 1,
    1, 1, 2, 2, 1, 1,
    -1, -1, -1, -1, 0, 2,
    1, 1, 2, 2, 1, 1,
    -1, -1, -1, -1, 2, 0};

char stack[30] = {'\0'};

string str[4] = {"E'->#E#", "E->T|E+T", "T->F|T*F", "F->i|(E)"};
typedef struct grammar
{
    char S;
    string G;
} Grammar;
Grammar wenfa[6];
// char input[30] = "((i+i)*i+i#";
// char input[30]="i+i#";
char input[30];
void init()
{
    wenfa[0].S = 'E';
    wenfa[0].G = "E+T";
    wenfa[1].S = 'E';
    wenfa[0].G = "T";
    wenfa[2].S = 'T';
    wenfa[2].G = "T*F";
    wenfa[3].S = 'T';
    wenfa[3].G = "F";
    wenfa[4].S = 'F';
    wenfa[4].G = "i";
    wenfa[5].S = 'F';
    wenfa[5].G = "(E)";
}

void output()
{
    cout << "文法为：" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << str[i] << endl;
    }
    cout << "符号表为:" << endl;
    char head[6] = {'+', '*', 'i', '(', ')', '#'};
    cout << "-------------------------------------------------------------------------------------" << endl;
    printf("|%6c     |%6c     |%6c     |%6c     |%6c     |%6c     |%6c     |\n", ' ', head[0], head[1], head[2], head[3], head[4], head[5]);
    for (int i = 0; i < 6; i++)
    {
        printf("|%6c     |", head[i]);
        for (int j = 0; j < 6; j++)
        {
            if (table[i][j] == 0)
                printf("%6c     |", '=');
            else if (table[i][j] == 1)
                printf("%6c     |", '>');
            else if (table[i][j] == -1)
                printf("%6c     |", '<');
            else
                printf("%6c     |", ' ');
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
}

int returnNum(char a, char b)
{
    int m = 0;
    int n = 0;
    switch (a)
    {
    case '+':
        m = 0;
        break;
    case '*':
        m = 1;
        break;
    case 'i':
        m = 2;
        break;
    case '(':
        m = 3;
        break;
    case ')':
        m = 4;
        break;
    case '#':
        m = 5;
        break;
    default:
        m = 6;
    }
    switch (b)
    {
    case '+':
        n = 0;
        break;
    case '*':
        n = 1;
        break;
    case 'i':
        n = 2;
        break;
    case '(':
        n = 3;
        break;
    case ')':
        n = 4;
        break;
    case '#':
        n = 5;
        break;
    default:
        n = 6;
    }
    return table[m][n];
}

void print0(int i)
{
    for (int j = i; input[j] != '\0'; j++)
        cout << input[j];
    cout << endl;
}

int main()
{
    output();
    while (cin >> input)
    {
        cout << "输入串为：" << input << endl;
        init();
        int top, bottom;
        stack[0] = '#';
        bottom = 0;
        top = 0;
        int cc = 0;
        int flag[5] = {0};
        int a = 0;
        int sign = 0;
        int x = 0;
        cout << "步数"
             << "----------"
             << "符号栈"
             << "----------"
             << "输入串" << endl;
        for (int i = 0; input[i] != '\0'; i++)
        {

            if (returnNum(stack[flag[a]], input[i]) == -1)
            {
                stack[++top] = input[i];
                flag[++a] = top;
                cout << x << "               " << stack << "            ";
                print0(i + 1);
                x++;
                continue;
            }
            else if (returnNum(stack[flag[a]], input[i]) == 1)
            {

                if (stack[top] == 'i')
                {
                    stack[top] = 'F';
                    i--;
                    a--;
                }
                else
                {
                    if (sign == 1)
                    {
                        a -= 2;
                        sign = 0;
                    }
                    else
                        a--;
                    int ss = -100;
                    for (int j = top; j > flag[a]; j--)
                    {
                        if (stack[top] == '+')
                            ss = 0;
                        if (stack[top] == '*')
                            ss = 1;
                        if (stack[top] == '(')
                            ss = 3;
                        stack[top--] = '\0';
                    }
                    if (ss == 0)
                    {
                        stack[++top] = 'E';
                        ss = -100;
                    }
                    else if (ss == 1)
                    {
                        stack[++top] = 'T';
                        ss = -100;
                    }
                    else if (ss == 3)
                    {
                        stack[++top] = 'F';
                        ss = -100;
                    }
                    i--;
                }
                cout << x << "               " << stack << "            ";
                print0(i + 1);
            }
            else if (returnNum(stack[flag[a]], input[i]) == 0)
            {
                stack[++top] = input[i];
                flag[++a] = top;
                sign = 1;
                cout << x << "               " << stack << "            ";
                print0(i + 1);
            }
            else
            {
                cout << "error" << endl;
                cc = 1;
                break;
            }
            x++;
        }
        if (cc == 0)
            cout << "success" << endl;
    }

    return 0;
}
