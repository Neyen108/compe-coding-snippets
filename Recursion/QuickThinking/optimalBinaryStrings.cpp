#include <bits/stdc++.h>

using namespace std;

int optimalBinaryStrings(int n)
{
    //base case
    //if length of string is 1, then 0 or 1,  two binary strings possible with no consecutive ones.
    if (n == 1)
    {
        return 2;
    }
    if (n == 0)
    {
        return 1;
    }

    return optimalBinaryStrings(n - 1) + optimalBinaryStrings(n - 2);
}

int main()
{
    cout << optimalBinaryStrings(3);
}