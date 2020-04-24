#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int p, q;
    cin >> p >> q;
    int n = p * q;
    int z = (p - 1) * (q - 1);
    for (int i = 2; i < n; i++)
        if (gcd(i, z) == 1)
            cout << i << endl;
    return 0;
}