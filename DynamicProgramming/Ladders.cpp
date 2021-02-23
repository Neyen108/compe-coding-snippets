#include <bits/stdc++.h>

using namespace std;

//Complexity = O(n.k)

//TOPDOWN
int numberOfWays(int n, int k, int dp[])
{
    //Base Case
    //if we are at the 0th step,
    //No. of ways to reach 0th step is 1
    if (n == 0)
    {
        return 1;
    }

    //Lookup table
    if (dp[n] != 0)
    {
        return dp[n];
    }

    //Recursion
    int ways = 0;

    //f(n) = f(n-1) + f(n-2) + f(n-3) +  .... + f(n-k)
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ways += numberOfWays(n - i, k, dp);
        }
    }

    dp[n] = ways;

    return dp[n];
}

//BottomUp
int numberOfWaysBottomUp(int n, int k)
{
    int dp[100] = {0};

    //To reach 0th step, we need 1 way
    dp[0] = 1;

    //dp[n] = dp[n-1] + dp[n-2] + ... + dp[n-k]

    for (int i = 1; i <= n; i++)
    {
        int ways = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                ways += dp[i - j];
            }
            dp[i] = ways;
        }
    }

    return dp[n];
}

//Optimised Approach O(n + k) == O(k)
int numberOfWaysOptimised(int n, int k)
{
    int dp[100] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i <= k)
        {
            dp[i] = 2 * dp[i - 1];
        }
        else
        {
            dp[i] = 2 * dp[i - 1] - dp[i - 1 - k];
        }
    }

    return dp[n];
}

int main()
{
    int dp[100] = {0};
    int k = 3;
    int n = 4;
    cout << numberOfWaysOptimised(n, k);
}