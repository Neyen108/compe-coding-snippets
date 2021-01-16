#include <iostream>
#include <vector>

using namespace std;

int p[1000000] = {0};
vector<int> primes;

void seive()
{
    //all odds are prime lol
    for (int i = 3; i < 1000000; i += 2)
    {
        p[i] = 1;
    }

    //0,1 not prime
    //2 prime
    p[0] = 0;
    p[1] = 0;
    p[2] = 1;
    primes.push_back(2);

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

vector<int> primeFactorisation(int n)
{

    vector<int> factors;

    for (int pr_no : primes)
    {
        if (pr_no * pr_no > n)
        {
            break;
        }

        if (n % pr_no == 0)
        {
            factors.push_back(pr_no);
            while (n % pr_no == 0)
            {
                n = n / pr_no;
            }
        }
    }

    if (n != 1)
    {
        factors.push_back(n);
    }
    return factors;
}

int main()
{
    seive();
    int n;
    cin >> n;
    vector<int> factors = primeFactorisation(n);
    for (int v : factors)
    {
        cout << v << " ";
    }
}