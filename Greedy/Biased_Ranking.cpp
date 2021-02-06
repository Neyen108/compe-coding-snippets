#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[1000000];
    while (t--)
    {
        memset(arr, 0, sizeof(arr));

        int n;
        cin >> n;

        string s;
        int desired_rank;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> desired_rank;
            arr[desired_rank]++;
        }

        int given_rank = 1;
        int badness = 0;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                badness += abs(given_rank - i);
                given_rank++;
                arr[i]--;
            }
        }

        cout << badness << "\n";
    }
}