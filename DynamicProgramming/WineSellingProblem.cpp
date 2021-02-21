#include <iostream>
#include <climits>

using namespace std;

int profit(int i, int j, int wines[], int dp[][100], int y)
{
    //base case
    //no more wine bottles
    if (i > j)
    {
        return 0;
    }

    //LOOKUP
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }

    //Optimal sub-structure

    //selling 1st bottle
    int op1 = (wines[i] * y) + profit(i + 1, j, wines, dp, y + 1);

    //selling last bottle
    int op2 = (wines[j] * y) + profit(i, j - 1, wines, dp, y + 1);

    dp[i][j] = max(op1, op2);

    return dp[i][j];
}

int main()
{
    int wines[] = {2, 3, 5, 1, 4};
    int i = 0;
    int j = 4;
    int dp[100][100] = {0};
    cout << profit(i, j, wines, dp, 1);
}