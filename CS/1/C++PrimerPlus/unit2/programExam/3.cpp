#include <iostream>
using namespace std;
void output1();
void output2();
int main()
{
    output1();
    output1();
    output2();
    output2();
    return 0;
}
void output1()
{
    cout<<"Three blind mice"<<endl;
}
void output2()
{
    cout<< "See how they run"<<endl;
}