#include <iostream>

using namespace std;

#define INT_MAX 1000000

int factorial_prime(int n, int k)
{
    int ans = INT_MAX;
    //prime factorise k

    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            int occ = 0; //occurence of factor i in denominator (k)
            while (k % i == 0)
            {
                occ++;
                k = k / i;
            }

            int cnt = 0; //count of factor i in numerator(n)
            long long int p = i;
            while ((n / p) > 0)
            {
                cnt = cnt + (n / p);
                p = p * i;
            }

            ans = min(ans, (cnt / occ));
        }
    }

    if (k != 1)
    {
        //k is a prime no. whose occurence is 1 in the denominator

        //finding count of k in numerator (n)
        int cnt = 0;
        long long int p = k;
        while ((n / p) > 0)
        {
            cnt = cnt + (n / p);
            p = p * k;
        }

        ans = min(ans, cnt);
    }

    if (ans == INT_MAX)
    {
        ans = 0;
    }
    return ans;
}

int main()
{
    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cout << factorial_prime(n, k);
    }
}