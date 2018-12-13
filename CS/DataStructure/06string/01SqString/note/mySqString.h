#ifndef MYSQSTRING_H
    #define MYSQSTRING_H
    #include "SqString.h"

class mySqString:public SqString
{
public:
    void getByRand(int display);
};

void mySqString::getByRand(int display = 1)
{
    this->clear();
    this->length = rand() % 20;

    fei(1, length)
    {
        ch[i] = 'a' + rand() % 26;
    }

    if(display)
        cout << ch;
}
#endif
