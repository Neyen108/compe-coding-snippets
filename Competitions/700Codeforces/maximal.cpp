#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mergingDone = 0;
    for (int i = 0; i < n; i++)
    {
        if (!s.empty())
        {
            if (a[i] == s.top())
            {
                while (i < n && a[i] == s.top())
                {
                    i++;
                }
                i--;
                mergingDone++;
            }
            else
            {
                s.push(a[i]);
            }
        }
        else
        {
            s.push(a[i]);
        }
    }

    cout << mergingDone + s.size();
}