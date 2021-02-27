#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int count[26] = {0};
        cin >> s;

        int n = s.length();
        if (n == 1 || n == 0)
        {
            cout << "NO"
                 << "\n";
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            count[c]++;
        }

        int odd_count = 0;

        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2 != 0)
            {
                odd_count++;
            }
        }

        int even_count = (n - odd_count) / 2;

        if (even_count >= odd_count)
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