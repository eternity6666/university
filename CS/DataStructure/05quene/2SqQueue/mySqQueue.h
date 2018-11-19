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
        cout << " [" << setw(2) << "]";
    cout << endl;
    int rear = this->rear;
    int front = this->front;
    if(rear < front)
    {
        fei(0, rear - 2)
            cout << "     ";
        cout << "↑";

        fei(rear, front - 2)
            cout << "     ";
        cout << "↑";
        
        fei(0, rear - 2)
            cout << "     ";
        cout << "rear";

        fei(rear, front - 2)
            cout << "     ";
        cout << "front";
    }
    else
    {
        fei(0, front - 2)
            cout << "     ";
        cout << "↑";
        
        fei(front, rear - 2)
            cout << "     ";
        cout << "↑";

        fei(0, front - 2)
            cout << "     ";
        cout << "front";

        fei(front - 2, rear)
            cout << "     ";
        cout << "rear";
    }
}

