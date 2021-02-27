#include <bits/stdc++.h>

using namespace std;

int noOfWays(int n, int *dp)
{
    //BASE CASE
    //no one goes = one way
    //if only one person is there, then he/she goes single = one way
    if (n == 0 || n == 1)
    {
        return 1;
    }

    //Lookup
    if (dp[n] != 0)
    {
        return dp[n];
    }

    //recursive

    //no of ways n people can go = [single(1) * no of ways n-1 people can go] + [no of ways a guy can get a partner(n-1) * no. of ways n-2 people can go]
    dp[n] = (1 * noOfWays(n - 1, dp)) + ((n - 1) * (noOfWays(n - 2, dp)));

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << noOfWays(n, dp);
}