//carrots.cpp -- food processing program
// uses and displays a variable

#include <iostream>

int main()
{
    using namespace std;

    //declare an integer variable
    int carrots;

    //assign a value to the variable
    carrots = 25;
    cout << "I have ";
    //display the value of the variable
    cout << carrots;
    cout << "carrots.";
    cout << endl;
    carrots = carrots - 1;
    cout << "Crunch,crunch. Now I have " << carrots << " carrots." << endl;
    return 0;
}