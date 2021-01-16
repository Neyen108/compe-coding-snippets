#include <iostream>
using namespace std;

int x, y;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, (a % b));
}

void extendedEuclidean(int a, int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }

    extendedEuclidean(b, (a % b));

    int currX = y;
    int currY = x - ((a / b) * y);

    x = currX;
    y = currY;
}

int main()
{
    int a, m;
    cin >> a >> m;

    //multiplicative inverse exists only if the gcd(a,m) == 1
    if (gcd(a, m) == 1)
    {
        extendedEuclidean(a, m);
        cout << (x + m) % m;
    }
    //else MI doesnt exist
    else
    {
        cout << "NO";
    }
}