#include "../../myhead.h"
#include <iomanip>

class sqString
{
public:
    void clear();

    bool getChar(int i, char &c);

    int getLength();

    void get_next(int *next, int display = 1);

    int index(sqString p, int pos);

    bool insert(int i, sqString t);

    bool isEmpty();

    sqString operator = (char *s);

    sqString operator = (const sqString s);

    sqString operator + (char *s);

    sqString operator + (const sqString s);

    int operator == (char *s);

    int operator == (const sqString s);

    bool operator < (const sqString s);

    bool operator > (const sqString s);

    bool strDelete(int i, int len);

    bool subString(sqString &sub, int i, int len);

    sqString();

    virtual ~sqString();

    sqString(char *s);

    sqString(const sqString &s);

    void read(istream &in);

    void display(ostream &out) const;

protected:
    void strAssign_aux(char *s);

    int length;
    char *ch;
};

void sqString::clear()
{
    if(ch)
    {
        delete[] ch;
        ch = NULL;
        length = 0;
    }
}

bool sqString::getChar(int i, char &c)
{
    if(i < 1 || i > length)
        return false;

    c = ch[i - 1];

    return true;
}

int sqString::getLength()
{
    return length;
}

void sqString::get_next(int *next, int display)
{
    int j = -1, i = 0;
    int first_i;
    char no[5] = " [i]";

    next[0] = -1;
    while(i < length)
    {
        if(j == -1 || ch[j] == ch[i])
        {
            ++j;
            ++i;
            next[i] = j;
        }
        else
            j = next[j];
    }

    if(display == 1)
    {
        cout << " 当前模式串的next[]数组为:\n";
        first_i = 0;
        while(first_i < length)
        {
            i = first_i;
            cout << "   ";
            do
            {
                if(i < 10)
                    no[2] = i + '0';
                else
                {
                    no[1] = i / 10 + '0';
                    no[2] = i % 10 + '0';
                }
                cout.width(5);
                cout.fill(' ');
                cout.setf(ios::right, ios::adjustfield);
                cout << no;
                ++i;
            }while(i % 10 && i < length);
            cout << endl;

            cout << "   ";
            i = first_i;
            do
            {
                cout.width(5);
                cout.fill(' ');
                cout.setf(ios::right, ios::adjustfield);
                cout << ch[i];
                ++i;
            }while(i % 10 && i < length);
            cout << endl;

            cout << "   ";
            i = first_i;
            do
            {
                cout.width(5);
                cout.fill(' ');
                cout.setf(ios::right, ios::adjustfield);
                cout << next[i];
                ++i;
            }while(i % 10 && i < length);
            
            first_i = i;
            cout << endl << endl;
        }
    }
}

int sqString::index(sqString p, int pos)
{
    int i = pos - 1;
    int j = 0;

    while(i < length && j < p.length)
    {
        if(ch[i] == p.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == p.length)
        return i - p.length + 1;
    else
        return 0;
}

int sqString::index_KMP(sqString p, int pos)
{
    int i = pos - 1;
    int j = -1;

    int *next;

    next = new int[p.length];
    assert(next != 0);

    p.get_next(next, 0);

    while(i < length && j < p.length)
    {
        if(j == -1 || ch[i] == p.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }

    if(j == p.length)
        return i - p.length + 1;
    else
        return 0;
}

bool sqString::insert(int i, sqString t)
{
    char *temp;

    if(i < 1 || i > length + 1 || t.isEmpty())
        return false;
    temp = new char[length + t.length];
    assert(temp != 0);
    for(int j = 0; j < i - 1; j++)
        temp[j] = ch[j];
    for(; j < i - 1 + t.length; j++)
        temp[j] = t.ch[j - i + 1];
    for(; j < length + t.length; j++)
        temp[j] = ch[j - t.length];

    delete []ch;
    ch = temp;
    length += t.length;
    return true;
}

bool sqString::isEmpty()
{
    return length ? false : true;
}

sqString sqString::operator = (char *s)
{
    strAssign_aux(s);
    return *this;
}

sqString sqString::operator = (sqString rightS)
{
    if(this != &rightS)
    {
        clear();
        ch = new char[rightS.length];
        assert(ch != 0);

        length = rightS.length;
        for(int i = 0; i < length; i++)
            ch[i] = rightS.ch[i];
    }
    return *this;
}

sqString sqString::operator + (char *s)
{
    insert(length + 1, s);
    return *this;
}

sqString sqString::operator + (sqString rightS)
{
    insert(length + 1, rightS);
    return *this;
}

bool sqString::operator < (sqString rightS)
{
    for(int i = 0; i < length && i < rightS.length; i++)
        if(ch[i] < rightS.ch[i])
            return true;
    
    if(i < rightS.length)
        return true;
    else
        return false;
}


