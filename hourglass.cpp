#include <bits/stdc++.h>

using namespace std;



int main()
{
    int arr[6][6];
    for(int i =0; i <6; i++)
    {
        for(int j=0; j<6; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max_max = INT_MIN;
    for(int i =1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            int sum = arr[i][j];
            int col =0;
            int row =i-1;
            for(int k=0; k<6; k++)
            {
                if(col == 3)
                {
                    row=row+2;
                    col =0;
                }
                sum = sum + arr[row][j-1+col];
                col++;
            }

            if(sum > max_max)
            {
                max_max = sum;
            }

        }
    }

    cout << max_max;


    return 0;
}

