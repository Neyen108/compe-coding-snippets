#include <bits/stdc++.h>

using namespace std;

//generate all possible subsequences
void subsequence(char *input, char *output, int i, int j)
{
    //base case
    //if we reach the end of input array
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << "\n";
        return;
    }

    //recursion
    //include 'a'
    output[j] = input[i];
    subsequence(input, output, i + 1, j + 1);

    //dont include 'a'
    subsequence(input, output, i + 1, j);
}

int main()
{
    char input[] = "abc";
    char output[10];
    subsequence(input, output, 0, 0);
}