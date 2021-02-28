#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool isDecreasing = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1]) //we found an increasing element
            {
                isDecreasing = false;
                break;
            }
        }

        if (isDecreasing == false)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}