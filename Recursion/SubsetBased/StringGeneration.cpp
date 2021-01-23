#include <bits/stdc++.h>

using namespace std;

void generateStrings(char *input, char *output, int i, int j)
{
    //base case
    //if we reach the end of input
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }

    //recursive call

    //only one number
    int firstNo = input[i] - '0';
    //if first number is 0, skip it
    if (firstNo == 0)
    {
        generateStrings(input, output, i + 1, j);
    }
    else
    {
        char c = firstNo + 'A' - 1; //converting the number to character
        output[j] = c;
        //call recursion on the remaining part
        generateStrings(input, output, i + 1, j + 1);

        //considering two digits
        if (input[i + 1] != '\0')
        {
            int secondNo = input[i + 1] - '0';
            int number = (firstNo * 10) + secondNo;
            if (number <= 26)
            {
                char d = number + 'A' - 1;
                output[j] = d;
                generateStrings(input, output, i + 2, j + 1);
            }
        }
    }

        return;
}

int main()
{
    char input[100];
    char output[100];
    cin >> input;
    generateStrings(input, output, 0, 0);
}