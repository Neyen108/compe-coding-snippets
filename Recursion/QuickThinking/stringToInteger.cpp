#include <bits/stdc++.h>

using namespace std;

int stringToInt(string s, int n)
{

    //base case
    //string of only one character
    if (n == 1)
    {
        return (s[n - 1] - '0');
    }

    //extract the last digit
    int digit = s[n - 1] - '0';

    //convert the remaining string to number
    int number = stringToInt(s, n - 1);

    return (number * 10 + digit);
}

int main()
{
    cout << stringToInt("12345", 5);
}