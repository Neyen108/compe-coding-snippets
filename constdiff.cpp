#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        int sign = -1;
        int i = 0;
        if(k==0)
        {
            for(i=0; i<n; i++)
            {
               cout << i+1 << " ";
            }
            cout << "\n";
        }
        else
        {
            for(i=0; i<n; i++)
            {
                if(i%k == 0)
                {
                    sign = sign*(-1);
                }
                a[i] = i+1 + (sign*k);

                if(a[i] > n)
                {
                    cout << "-1" << "\n";
                    break;
                }
            }
            if(i == n)
            {
                for(int x=0; x<n; x++)
                {
                   cout << a[x] << " ";
                }
                cout << "\n";
            }
        }

    }
}
