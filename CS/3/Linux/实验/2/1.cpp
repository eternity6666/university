#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int ans, guess;
    srand((unsigned int)time(NULL));
    ans = rand() % 1000;
    // cout << ans << endl;
    do
    {
        cout << "Enter your number:\n";
        cin >> guess;
        if (guess == ans)
            break;
        else if (guess > ans)
            cout << "Your number is big\n";
        else
            cout << "YOur number is small\n";
    } while (1);
    cout << "Great!" << endl;
    return 0;
}