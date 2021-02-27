#include <bits/stdc++.h>

using namespace std;

int cellMitosis(int n, int x, int y, int z)
{
    int dp[100] = {0};

    //to construct 0 cells, i need 0 cost
    dp[0] = 0;
    //to construct 1 cell, i need 0 cost as it is already there
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        //if even, only care about the double and increment
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }
        //if odd, care about increment and double + decrement
        else
        {
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        }
    }

    return dp[n];
}

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << cellMitosis(n, x, y, z);
}