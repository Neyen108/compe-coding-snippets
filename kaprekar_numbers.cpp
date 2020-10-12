#include <bits/stdc++.h>

using namespace std;

void kaprekarNumbers(int p, int q) 
{
    long long first = p;
    long long last = q;
    int flag = 0;
    for(long long i = first; i<=last; i++)
    {
        string str_i = to_string(i);
        int d = str_i.length();

        long long div = 1;

        for(int k=0; k<d; k++)
        {
            div = div *  10;
        }

        long long square = i*i;
        long long left = square/div;
        long long right = square % div;
        if(left + right == i)
        {
            cout << i << " ";
            flag = 1;
        }
    }
    if(flag == 0)
    {
        cout << "INVALID RANGE";
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
