# HomeWork 1

## Personal Message

姓名|学号|班级
---|---|---
阳作华|6109117050|计算机科学与技术(软件技术)174班

本次作业采用的编程语言是```C++```, 一共有4个文件, 分别是**main.h**和**answer1.cpp**和**answer2.cpp**和**answer3.cpp**.

其中**main.h**的内容如下

```C++
//main.h
#ifndef MY_MAIN_H
    #define MY_MAIN_H

typedef enum
{
    EAST,
    WEST
} Destination;

class Same
{
private:
    Destination destination;
    int id;
    bool waiting;
    bool crossing;
    bool crossed;

public:
    Same(int id, Destination dest);
    Destination getDest();
    void waitUntilSafeToCross();
    void crossRavine();
    void doneWithCrossing();
};

Same::Same(int id, Destination dest)
{
    this->id = id;
    this->waiting = true;
    this->crossing = false;
    this->crossed = false;
    this->destination = dest;
}

Destination Same::getDest()
{
    return this->destination;
}

void Same::waitUntilSafeToCross()
{
    this->waiting = true;
    this->crossing = false;
    this->crossed = false;
}

void Same::crossRavine()
{
    this->waiting = false;
    this->crossing = true;
    this->crossed = false;
}

void Same::doneWithCrossing()
{
    this->waiting = false;
    this->crossing = false;
    this->crossed = true;
}
#endif
```

## The answer of problem(a)

**answer1.cpp**内容如下:

```C++
//answer1.cpp
#include <iostream>
#include <cstdlib>
#include <vector>
#include "main.h"
using namespace std;

class PigInProblemA : public Same
{
public:
    PigInProblemA(int id, Destination dest):Same(id, dest){}
};

vector<PigInProblemA> ve;

void crossRavine(int id, Destination dest)
{
    ve[id - 1].crossRavine();
}

void doneWithCrossing(int id, Destination dest)
{
    ve[id - 1].doneWithCrossing();
}

void pig(int id, Destination dest)
{
    crossRavine(id, dest);
    doneWithCrossing(id, dest);
}

int main()
{
    int num = int(rand() * 100) % 5 + 1;
    for (int i = 0; i < num; ++i)
        ve.push_back(PigInProblemA(i + 1, EAST));
    for (int i = 0; i < num; ++i)
        pig(i + 1, (ve[i].getDest() == WEST ? EAST : WEST));
    return 0;
}
```

## The answer of problem(b)

**answer2.cpp**内容如下:

```C++
//answer2.cpp
```

## The answer of problem(c)

**answer3.cpp**内容如下:

```C++
//answer3.cpp
```
