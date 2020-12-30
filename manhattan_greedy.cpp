#include<bits/stdc++.h>

using namespace std;

/*
    sort first
    consider 3, 5 , 7, 9
    dist of all pairs smaller than 3 = 0
    dist of all pairs smaller than 5 = dist of all pairs smaller than 3 + (5-3) = 2
    dist of all pairs smaller than 7 = dist of all pairs smaller than 5 + (7-5 + 7-3) or (7*number of numbers smaller than 7 - sum till 7) = 8
    dist of all pairs smaller than 9 = smallerpairs 7 + (9*3 - (3+5+7)) = 8 +

*/

int distancefor(int a[], int n)
{
    sort(a, a+n);
    int dist = 0;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        dist = dist + (a[i]*i - sum);
        sum = sum + a[i];
    }
    return dist;
}
int totaldistancesum(int x[], int y[], int n)
{
    return distancefor(x, n) + distancefor(y, n);
}

int main()
{
    int x[] = { -1, 1, 3, 2 };
    int y[] = { 5, 6, 5, 3 };
    int n = sizeof(x) / sizeof(x[0]);
    cout << totaldistancesum(x, y, n) << "\n";
    return 0;
}
