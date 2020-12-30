#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int temp = n;
    int rem=0;
    int sum=0;

    vector <int> binary;
    while(temp != 0)
    {
        rem = temp%2;
        temp = temp/2;
        binary.push_back(rem);
    }

    
    vector <int> a;
    int count =0;

    for(int j =0; j<binary.size(); j++)
    {
        if(binary[j]==0)
        {
            a.push_back(count);
            count=0;
        }
        else
        {
            count++;
        }
    }

    a.push_back(count);

    int maxb = *max_element(a.begin(), a.end());

    cout << maxb;


    return 0;
}
