#include <bits/stdc++.h>

using namespace std;

void permute(char *input, int i)
{

    //base case
    if (input[i] == '\0')
    {
        cout << input << endl;
        return;
    }

    //recursuion
    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        permute(input, i + 1);
        swap(input[i], input[j]);
    }
}

int main()
{
    char input[100];
    cin >> input;
    permute(input, 0);
}