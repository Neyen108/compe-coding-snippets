#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[10];
        int k;
        for (int i = 0; i < 10; i++)
        {
            cin >> a[i];
        }
        cin >> k;

        for (int i = 9; i >= 0; i--)
        {
            int curr_elem = a[i];

            a[i] = a[i] - k;

            if (a[i] < 0)
            {
                a[i] = 0;
            }

            k = k - curr_elem;
            if (k < 0)
            {
                k = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (a[i] != 0)
            {
                ans = i;
            }
        }

        cout << ans;
    }
}