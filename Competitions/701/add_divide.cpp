#include <bits/stdc++.h>

using namespace std;

int solve(long long int a, long long int b)
{
    if (a / b == 0)
    {
        return 1;
    }

    return solve(a / b, b) + solve(a, b + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        cout << solve(a, b, 0);
    }
}