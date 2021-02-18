#include <bits/stdc++.h>

using namespace std;

int fibo(int n, int *dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    return dp[n];
}

int main()
{
    int dp[100] = {0};

    cout << fibo(6, dp);
}
