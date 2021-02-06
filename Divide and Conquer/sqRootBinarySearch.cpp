#include <bits/stdc++.h>

using namespace std;

float sqRoot(int n, int p)
{
    int l = 1;
    int r = n;

    float ans = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    float inc = 0.1;            //increment per decimal
    for (int i = 0; i < p; i++) //precision
    {
        while (ans * ans < n) //increment ans till we get the correct value
        {
            ans = ans + inc;
        }

        ans = ans - inc; //since we overshot the value (due to the while loop condition), we subtract
        inc = inc / 10;  //reduce the increment
    }

    return ans;
}

int main()
{
    cout << sqRoot(50, 3);
}