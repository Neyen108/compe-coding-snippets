#include <iostream>
using namespace std;

void primeSeive(int *p)
{

    p[0] = 0;
    p[1] = 0;
    p[2] = 1;

    //mark all odds as prime i.e get all evens out
    for (int i = 3; i < 1000000; i += 2)
    {
        p[i] = 1;
    }

    //Seive
    for (long long i = 3; i < 1000000; i += 2)
    {
        //if the current number is prime
        if (p[i] == 1)
        {
            for (long long j = i * i; j < 1000000; j += i)
            {
                //mark all the multiples of prime p[i] as not prime
                p[j] = 0;
            }
        }
    }
}

int main()
{
    int p[1000000] = {0};

    primeSeive(p);

    int n;
    cin >> n;

    //print all the primes
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }
}