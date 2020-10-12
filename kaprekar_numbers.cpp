#include <bits/stdc++.h>

using namespace std;

void kaprekarNumbers(int p, int q) 
{
    // Storing the range in long long to prevent overflow
    long long first = p;
    long long last = q;

    //flag to detect if there are any kaprekar numbers 
    int flag = 0;

    //checking all numbers between p and q
    for(long long i = first; i<=last; i++)
    {
        //converting the number to string, and then finding the no of digits, d, of the number i
        string str_i = to_string(i);
        int d = str_i.length();

        // 10^d
        long long div = 1;
        for(int k=0; k<d; k++)
        {
            div = div * 10;
        }

        //square of the number
        long long square = i*i;

        //right has d digits
        long long left = square / div;
        long long right = square % div;

        //if its a kaprekar number print
        if(left + right == i)
        {
            flag = 1;
            cout << i << " ";
        }

        // if no kaprekar numbers are found
        if(flag == 0)
        {
            cout << "INVALID RANGE";
        }
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
