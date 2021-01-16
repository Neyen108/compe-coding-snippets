#include <iostream>
#include <vector>

using namespace std;

#define N 100005

int pr[N];

vector<int> primes;

// we need primes till 10^5  --> cause max value of n = 10^9  --> root(10^9) ~~ 10^5
//function to get the primes till 10^5
void seive()
{
    //assume all are primes
    for (int i = 0; i < N; i++)
    {
        pr[i] = 1;
    }

    pr[0] = 0;
    pr[1] = 0;
    for (long long int i = 2; i < N; i++)
    {
        if (pr[i] == 1)
        {
            primes.push_back(i);
            //all multiples of prime i
            for (long long int j = i * i; j < N; j += i)
            {
                pr[j] = 0;
            }
        }
    }
}

void solve(int m, int n)
{
    int size = n - m + 1;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 1;
    }

    for (int pr_no : primes)
    {
        //if pr_no is greater then root(n)
        if (pr_no * (long long int)pr_no > n)
        {
            break;
        }

        //get the starting pos
        int start = (m / pr_no) * pr_no;

        //prime no. lies in the arr
        if (pr_no >= m && pr_no <= n)
        {
            start = pr_no * 2;
        }

        //mark all the multiples of pr_no as not prime
        for (int i = start; i <= n; i += pr_no)
        {
            arr[i - m] = 0;
        }
    }

    //show all primes from m to n inclusive
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1 && i + m != 1)
        {
            cout << i + m << endl;
        }
    }
}

int main()
{
    seive();
    int m, n;
    cin >> m >> n;
    solve(m, n);
}
