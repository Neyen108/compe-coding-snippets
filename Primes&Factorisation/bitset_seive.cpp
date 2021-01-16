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

int main()
{
    bitsetSeive();
    int n;
    cin >> n;

    //first n primes
    for (int i = 0; i < n; i++)
    {
        cout << primes[i] << " ";
    }
}
