#include <bits/stdc++.h>

using namespace std;

int main()
{
    //get the strings
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    map<char, int> freq_s1, freq_s2;

    //get the frequency of all characters of string s2

    for (char x : s2)
    {
        freq_s2[x]++;
    }

    //get the size of s1
    int n = s1.size();

    //initialize the first pointer
    int l = 0;

    int res_l = -1, res_r = 1e9; //actual result

    //two pointer approach
    for (int r = 0; r < n; r++)
    {
        //increment frequency of s[r]
        freq_s1[s1[r]]++;

        bool good_window = true;

        //check if the window is good
        for (pair<char, int> x : freq_s2)
        {
            //if in s1 (till now) the char of s2 doesnt exist,
            //or if the freq of any char of s2 in s1 is less,
            //then bad string, keep incrementing r
            if ((freq_s1.count(x.first) == 0) || freq_s1[x.first] < x.second)
            {
                good_window = false;
                break;
            }
        }

        if (!good_window)
            continue;

        //increment l if freq of s[l] in s1 is greater than freq of s[l] in s2
        //or if in s2.. s[l] doesnt exist
        while (l < n && l <= r && (freq_s2.count(s1[l]) == 0 || freq_s1[s1[l]] > freq_s2[s1[l]]))
        {
            freq_s1[s1[l]]--;
            if (freq_s1[s1[l]] == 0)
                freq_s1.erase(s1[l]);
            l++;
        }

        if (res_r - res_l + 1 > r - l + 1)
        {
            res_r = r;
            res_l = l;
        }
    }
    if (res_l == -1)
    {
        cout << "No String";
    }
    else
    {
        cout << s1.substr(res_l, res_r - res_l + 1);
    }
}