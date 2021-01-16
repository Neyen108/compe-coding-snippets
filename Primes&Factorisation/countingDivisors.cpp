#include <iostream>
#include <vector>

using namespace std;

int p[1000000] = {0};
vector<int> primes;

void seive()
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 1;
    primes.push_back(2);

    //all odd
    for (int i = 3; i < 1000000; i += 2)
    {
        p[i] = 1;
    }

    //seive
    for (long long int i = 3; i < 1000000; i += 2)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
            for (long long int j = i * i; j < 1000000; j += i)
            {
                p[j] = 0;
            }
        }
    }
}

int count_factors(int n)
{
    int ans = 1;

    for (int pr_no : primes)
    {
        if (pr_no * pr_no > n)
        {
            break;
        }

        if (n % pr_no == 0)
        {
            int count = 0;
            while (n % pr_no == 0)
            {
                count++;
                n = n / pr_no;
            }
            ans = ans * (count + 1);
        }
    }

    if (n != 1) //n is a prime no itself
    {
        ans = ans * (1 + 1);
    }

    return ans;
}

int main()
{
    seive();
    int n;
    cin >> n;
    cout << count_factors(n);
}
