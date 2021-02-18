#include <iostream>
#include <climits>

using namespace std;

int minSteps(int n, int *dp)
{
    //Base Case
    //0 steps to reach 1 from 1
    if (n == 1)
    {
        return 0;
    }

    //dp array
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = minSteps(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minSteps(n / 2, dp) + 1;
    }
    op3 = minSteps(n - 1, dp) + 1;

    dp[n] = min(min(op1, op2), op3);

    return dp[n];
}

int main()
{
    int dp[100] = {0};
    cout << minSteps(10, dp);
}
