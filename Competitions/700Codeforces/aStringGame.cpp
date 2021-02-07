#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    
    while (t--)
    {
        int turn = 1;
        string str;
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            if (turn == 1)
            {
                if (str[i] == 'a')
                {
                    str[i] = 'b';
                }
                else
                {
                    str[i] = 'a';
                }
            }
            else
            {
                if (str[i] == 'z')
                {
                    str[i] = 'y';
                }
                else
                {
                    str[i] = 'z';
                }
            }
            turn = turn * (-1);
        }

        cout << str << "\n";
    }
}