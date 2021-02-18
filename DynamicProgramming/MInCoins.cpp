#include <iostream>
#include <climits>

using namespace std;

int minCoinsTopDown(int amount, int coins[], int *dp)
{
    //base case
    //we need 0 coins to make 0
    if (amount == 0)
    {
        return 0;
    }

    //dp array
    if (dp[amount] != 0)
    {
        return dp[amount];
    }

    //top down tree
    int ans = INT_MAX;
    int i = 0;
    while (amount - coins[i] >= 0)
    {
        ans = min(ans, minCoinsTopDown(amount - coins[i], coins, dp));
        i++;
    }

    dp[amount] = ans + 1;

    return dp[amount];
}

int minCoinsBottomUp(int amount, int coins[])
{
    int dp[100] = {0};

    //bottom up
    //
    for (int i = 1; i <= amount; i++)
    {
        int k = 0;
        int ans = INT_MAX;
        while (i - coins[k] >= 0)
        {
            ans = min(ans, dp[i - coins[k]]);
            k++;
        }
        dp[i] = ans + 1;
    }

    return dp[amount];
}

int main()
{
    int coins[] = {1, 3, 5};
    int dp[100] = {0};
    cout << minCoinsTopDown(8, coins, dp) << "\n";
    cout << minCoinsBottomUp(8, coins);
}
