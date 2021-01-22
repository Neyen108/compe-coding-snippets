#include <bits/stdc++.h>

using namespace std;

int profit(int *weights, int *prices, int n, int c)
{
    //base case
    //if all the products have been traversed
    //or if there is no more capacity
    if (n == 0 || c == 0)
    {
        return 0;
    }

    //include the last element
    int include = 0;
    if (c >= weights[n - 1])
    {
        include = prices[n - 1] + profit(weights, prices, n - 1, c - weights[n - 1]);
    }
    //exclude the last element
    int exclude = profit(weights, prices, n - 1, c);

    return max(include, exclude);
}

int main()
{
    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};

    int n = 4; //size of array
    int c = 7; //capacity

    cout << profit(weights, prices, n, c);
}