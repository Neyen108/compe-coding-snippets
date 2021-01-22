#include <bits/stdc++.h>

using namespace std;

int ladders(int n, int k)
{
    //base case
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    //f(n) = f(n-1)
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += ladders(n - i, k);
    }

    return ans;
}

int main()
{
    int n, jumps;
    cin >> n >> jumps;
    cout << ladders(n, jumps);
}