#include <bits/stdc++.h>

using namespace std;

int main()
{
    //test cases
    int t;
    cin >> t;

    long long int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    while (t--)
    {
        long long int n;
        cin >> n;

        int subsets = 1 << 8;

        long long int ans = 0;

        for (int i = 1; i < subsets; i++)
        {
            long long int denominator = 1;
            int setBits = 0;
            int j = 0;
            int temp = i;
            while (temp > 0)
            {
                if (temp & 1)
                {
                    denominator = denominator * primes[j];
                    setBits++;
                }
                j++;
                temp = temp >> 1;
            }

            if (setBits & 1)
            {
                ans = ans + (n / denominator);
            }
            else
            {
                ans = ans - (n / denominator);
            }
        }

        cout << ans << "\n";
    }
}