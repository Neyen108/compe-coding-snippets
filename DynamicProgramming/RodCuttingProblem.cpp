#include <bits/stdc++.h>

using namespace std;

//Naive approach (modify to top down DP)

int max_profit(int *prices, int n)
{
    //Base case
    if (n == 0)
    {
        return 0;
    }

    //recursive case
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;

        //option(i) = price of that cut + profit(n - cut)
        int current_ans = prices[i] + max_profit(prices, n - cut);

        ans = max(ans, current_ans);
    }

    return ans;
}

//DP approach
//Bottom Up
int max_profitBottomUp(int *prices, int n)
{
    //lookup array to store the max-profit for each length
    int dp[100] = {0};

    //profit from length 0 is 0
    dp[0] = 0;

    //find max profit for all possible lengths
    for (int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;
        //find max profit
        //make various cuts and sell
        for (int j = 0; j < len; j++)
        {
            int cut = j + 1;
            int current_ans = prices[j] + dp[len - cut];
            ans = max(ans, current_ans);
        }

        dp[len] = ans;
    }

    return dp[n];
}

int main()
{
    int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);

    cout << max_profitBottomUp(prices, n);
}