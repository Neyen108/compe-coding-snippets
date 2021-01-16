#include <iostream>
using namespace std;

int fastModuloExponentiation(long long int a, long long int exp, long long int m)
{
    int res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        exp = exp >> 1;
    }
    return res;
}

int main()
{
    long long int a, exp, m;
    cin >> a >> exp >> m;
    cout << fastModuloExponentiation(a, exp, m);
}
