#include <iostream>

using namespace std;

bool solve(long long int n, long long int m, long long int p, long long int a, long long int b)
{
    if (n == 0 || m == 0)
    {
        return false;
    }

    if (n * m == p || n == p || m == p || a * b == p)
    {
        return true;
    }

    if (n * m < p)
    {
        return false;
    }

    bool right = solve(n - 1, m, p, n, (b ? m - 1 : 0));
    bool down = solve(n, m - 1, p, (b ? n - 1 : 0), m);

    if (right || down)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, p;
        cin >> n >> m >> p;

        if (solve(n, m, p, 0, 0))
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}