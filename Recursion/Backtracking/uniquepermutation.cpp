#include <bits/stdc++.h>

using namespace std;

void permute(char *input, int i, set<string> &s)
{
    //base case
    if (input[i] == '\0')
    {
        string t(input);
        s.insert(t);
        return;
    }

    //recursuion
    for (int j = i; input[j] != '\0'; j++)
    {
        swap(input[i], input[j]);
        permute(input, i + 1, s);
        swap(input[i], input[j]);
    }
}

int main()
{
    char input[100];
    cin >> input;
    set<string> s;
    permute(input, 0, s);

    for (string x : s)
    {
        cout << x << endl;
    }
}