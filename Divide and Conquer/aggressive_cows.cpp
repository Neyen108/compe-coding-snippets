#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(long long int stalls[], int n, int cows, long long int minSep)
{

    long long int lastCowPos = stalls[0];

    int count = 1; //already placed a cow

    for (int i = 1; i < n; i++)
    {

        if (stalls[i] - lastCowPos >= minSep)
        {

            lastCowPos = stalls[i];
            count++;
            if (count == cows)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, cows;
    cin >> n >> cows;

    long long int stalls[n];

    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    sort(stalls, stalls + n);

    //binary search

    long long int ans = 0;
    long long int l = 0;
    long long int r = stalls[n - 1] - stalls[0];

    while (l <= r)
    {
        long long int mid = (l + r) / 2;

        if (canPlaceCows(stalls, n, cows, mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans;
}