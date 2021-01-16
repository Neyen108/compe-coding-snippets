//26A

#include <iostream>
#include <vector>

using namespace std;

int seive(int n)
{
    int primeDivisorCount[n + 1];   //holds the no. of prime divisors a number has
    for (int i = 0; i <= n; i++)
    {
        primeDivisorCount[i] = 0;
    }

    vector<int> primes;

    for (int i = 2; i <= n; i++)
    {
        if (primeDivisorCount[i] == 0)
        {
            primes.push_back(i);

            //mark all multiples of i including i itself
            for (int j = i; j <= n; j += i)
            {
                primeDivisorCount[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primeDivisorCount[i] == 2)
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << seive(n);
}