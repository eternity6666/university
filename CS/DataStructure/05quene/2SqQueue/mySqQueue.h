#include "SqQueue.h"

template <typename elemtype>
class mySqQueue<elemtype>:public:SqQueue<elemtype>
{
    public:
        void display();
}

template <typename elemtype>
void mySqQueue<elemtype>::display()
{
    fei(1, queueSize)
        cout << " [" << setw(2) << "]";
    cout << endl;
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

