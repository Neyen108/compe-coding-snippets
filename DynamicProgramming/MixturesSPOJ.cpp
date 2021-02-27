#include <bits/stdc++.h>

using namespace std;

int arr[1000] = {0};

long long int sum(int a, int b)
{
    long long int ans = 0;
    for (int i = a; i <= b; i++)
    {
        ans += arr[i];
        ans = ans % 100;
    }
    return ans;
}

int minSmoke(int i, int j, long long int dp[][100])
{
    //Base Case
    if (i >= j)
    {
        return 0;
    }

    //LookUp
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    //recursive
    long long int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, minSmoke(i, k, dp) + minSmoke(k + 1, j, dp) + sum(i, k) * sum(k + 1, j));
    }

    dp[i][j] = ans;

    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int dp[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << minSmoke(0, n - 1, dp);
}