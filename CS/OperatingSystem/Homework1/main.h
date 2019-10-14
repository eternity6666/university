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
