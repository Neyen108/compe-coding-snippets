#include <bits/stdc++.h>

using namespace std;

char keypad[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypadString(char *input, char *output, int i, int j)
{

    //base case
    //if we reach the end of input
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    //recursive
    int digit = input[i] - '0';

    //if digit is 1 or 0
    //just skip the input
    if (digit == 1 || digit == 0)
    {
        keypadString(input, output, i + 1, j);
    }

    //for others take the charaters
    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        output[j] = keypad[digit][k];
        keypadString(input, output, i + 1, j + 1);
    }
}

int main()
{
    char input[100];
    cin >> input;
    char output[100];
    keypadString(input, output, 0, 0);
}