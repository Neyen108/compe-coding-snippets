#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, (a % b));
}

int modInverse(int a, int m)
{
    if (m == 1)
        return 0;

    int m0 = m, y = 0, x = 1;

    while (a > 1)
    {
        int q = a / m, t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

void solve()
{
    int n, p, w, d;
    cin >> n >> p >> w >> d;

    //gcd of w,d
    int g = gcd(w, d);

    //if not divisible by gcd then cannot solve diophantine
    if (p % g != 0)
    {
        cout << -1;
        return;
    }

    //even after winning all, dont have enough points
    if (n * w < p)
    {
        cout << -1;
        return;
    }

    //update values
    w = w / g;
    d = d / g;
    p = p / g;

    //get the no. of draws
    int y = ((p % w) * modInverse(d, w)) % w;

    //get no. of wins
    int x = (p - y * d) / w;

    //if wins are -ve
    if (x < 0)
    {
        cout << -1;
        return;
    }

    //if wins + draws > no. of games
    if (x + y > n)
    {
        cout << -1;
        return;
    }

    cout << x << " " << y << " " << n - (x + y);
}

int main()
{
    solve();
}