#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, k;
    cin >> n >> q >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = (a[l] - 1) + (k - a[r]);
        for (int i = l; i < r; i++)
        {
            ans += ((a[i + 1] - a[i] - 1) * 2);
        }
        cout << ans << "\n";
    }
}