#include <bits/stdc++.h>

using namespace std;

void brackets(int n, char *output, int i, int open, int close)
{
    //base case
    //if we reach the end of the output array
    if (i == 2 * n)
    {
        output[i] = '\0';
        cout << output << endl;
        return;
    }

    //recursive call

    //if no. of opening brackets is less than n
    //put an opening bracket, open++
    if (open < n)
    {
        output[i] = '(';
        brackets(n, output, i + 1, open + 1, close);
    }

    //if no. of closing brackets is < opening brackets
    //put a closing bracket, close++
    if (close < open)
    {
        output[i] = ')';
        brackets(n, output, i + 1, open, close + 1);
    }
}

int main()
{
    char output[100];
    brackets(2, output, 0, 0, 0);
}