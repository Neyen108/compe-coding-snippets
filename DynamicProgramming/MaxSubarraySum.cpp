#include <iostream>

using namespace std;

//here we can make modifications to get the indexes of the subarray
//index r = max
//index l = the first 0 while going left from max(r)
int maxSubArraySum(int arr[], int n)
{
    //dp array
    int dp[100] = {0};

    //if -ve then put 0
    dp[0] = arr[0] > 0 ? arr[0] : 0;

    //keep track of max
    int max_so_far = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + arr[i];

        //if -ve then reset
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }

    return max_so_far;
}

//space optimisation
int maxSubArraySumOptimized(int arr[], int n)
{
    int currentSum = 0;
    int max_so_far = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];

        //if sum becomes -ve: reset to 0
        if (currentSum < 0)
        {
            currentSum = 0;
        }

        max_so_far = max(max_so_far, currentSum);
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};

    int n = sizeof(arr) / sizeof(int);

    cout << maxSubArraySum(arr, n) << "\n";

    cout << maxSubArraySumOptimized(arr, n);
}