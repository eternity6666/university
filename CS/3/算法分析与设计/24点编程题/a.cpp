#include <iostream>
using namespace std;

int main()
{
    cout << 13 * 13 * 13 * 13 << endl;
    for (int i = 1; i <= 13; ++i)
        for (int j = 1; j <= 13; ++j)
            for (int k = 1; k <= 13; ++k)
                for (int z = 1; z <= 13; ++k)
                    cout << i << " " << j << " " << k << " " << z << endl;
}