#include <bits/stdc++.h>

using namespace std;

bool canCookInTime(int ranks[], int n, int prata, int min_time)
{
    int rotis = 0;
    for (int i = 0; i < n; i++)
    {
        int rank = ranks[i];
        int time = min_time;
        int n = 1;
        while ((time - (n * rank)) >= 0)
        {
            time = time - (n * rank);
            rotis++;
            n++;
            if (rotis == prata)
            {
                return true;
            }
        }
    }
    return false;
}

int findMinTime(int ranks[], int n, int prata)
{
    int l = 0;

    int max_time = 0;
    for (int i = 1; i <= prata; i++)
    {
        max_time += (i * ranks[0]);
    }

    int r = max_time;

    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (canCookInTime(ranks, n, prata, mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int prata;
        cin >> prata;

        int n;
        cin >> n;
        int ranks[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ranks[i];
        }

        cout << findMinTime(ranks, n, prata);
    }
}