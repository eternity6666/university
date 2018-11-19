#include "SqQueue.h"

template <typename elemtype>
class mySqQueue:public SqQueue<elemtype>
{
public:
    void display();

    void getByRand(int display);

};

template <typename elemtype>
void mySqQueue<elemtype>::getByRand(int display)
{
    this->clear();

    int n = rand() % 8;
    int array[10];
    fei(0, n - 1)
    {
        array[i] = rand() % 100;
        if(display)
        {
            cout.width(5);
            cout.fill(' ');
            cout << array[i];
        }
        this->enQueue(array[i]);
    }
    if(display)
        cout << endl;
}

template <typename elemtype>
void mySqQueue<elemtype>::display()
{
    fei(1, this->queueSize)
        cout << " [" << setw(2) << i << "]";
    cout << endl;
    int rear = this->rear;
    int front = this->front;
    if(rear < front)
    {
        fei(0, this->queueSize - 1)
        {
            cout.width(5);
            cout.fill(' ');
            if(i < rear)
                cout << this->base[i];
            else if(i < front)
                cout << ' ';
            else
                cout << this->base[i];
        }
    }
    else
    {
        fei(0, this->queueSize - 1)
        {
            cout.width(5);
            cout.fill(' ');
            if(i < front)
                cout << ' ';
            else if(i < rear)
                cout << this->base[i];
            else
                cout << ' ';
        }
    }
    cout << endl;
    
    fei(0, this->queueSize - 1)
    {
        if(i == rear || i == front)
            cout << "   ↑ ";
        else
        {
            cout.width(5);
            cout.fill(' ');
            cout << ' ';
        }
    }
    cout << endl;

    fei(0, this->queueSize - 1)
    {
        cout.width(5);
        cout.fill(' ');
        if(i == rear)
            cout << " rear";
        else if(i == front)
            cout << " front";
        else
            cout << ' ';
    }
    cout << endl;
}

