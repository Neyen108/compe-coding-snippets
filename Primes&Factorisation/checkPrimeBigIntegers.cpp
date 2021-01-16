#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

//useful for getting the first n primes
bitset<10000000> b;
vector<int> primes;

void bitsetSeive()
{

    //set all as primes
    b.set();

    b[0] = 0;
    b[1] = 0;

    for (long long int i = 2; i < 10000000; i++)
    {
        if (b[i])
        {

            primes.push_back(i);
            for (long long int j = i * i; j < 10000000; j = j + i)
            {
                b[j] = 0;
            }
        }
    }
}

bool isPrime(long long int no)
{

    if (no < 10000000)
    {
        return b[no];
    }

    //checking if the prime  number is <= sq.root(no)
    for (int i = 0; primes[i] * (long long int)primes[i] <= no; i++)
    {
        if (no % primes[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    bitsetSeive();

    if (isPrime(2147483647))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}
