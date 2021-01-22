#include <bits/stdc++.h>

using namespace std;

int replaceTiles(int n)
{
    //base case
    if (n <= 3)
    {
        return 1;
    }

    // recursive case
    return replaceTiles(n - 1) + replaceTiles(n - 4);
}

int main()
{
    cout << replaceTiles(10);
}