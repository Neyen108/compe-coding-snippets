#include <iostream>
#include <vector>

using namespace std;

int p[100005] = {0};

vector<int> primes;

void seive()
{

    p[2] = 1;
    primes.push_back(2);
    //all odds
    for (int i = 3; i < 100005; i += 2)
    {
        p[i] = 1;
    }

    for (long long int i = 3; i < 100005; i += 2)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
            for (long long int j = i * i; j < 100005; j += i)
            {
                p[i] = 0;
            }
        }
    }
}

bool find_product_numbers(int n)
{
    int orginal_no = n;
    vector<pair<int, int>> factors;

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
            factors.push_back(make_pair(pr_no, count));
        }
    }

    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }

    if (factors.size() == 0)
    {
        return false;
    }

    if (factors.size() >= 3)
    {
        return true;
    }

    if (factors.size() == 2)
    {
        int a = factors[0].first;
        int b = factors[1].first;
        int x = orginal_no / (a * b);
        if (x != a && x != b)
        {
            if (x > 1)
            {
                return true;
            }
        }
        return false;
    }

    if (factors.size() == 1)
    {
        if (factors[0].second >= 6)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    seive();
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        if (find_product_numbers(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}