#include <bits/stdc++.h>

using namespace std;

int main()
{
    //no of chopsticks and limit
    int n, D;
    cin >> n >> D;

    //array to store chopsticks length
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //sort the array accordind to the length
    sort(arr, arr + n);

    int pairs = 0;
    int i = 0;

    while (i + 1 < n)
    {
        //ofc we will pair a chopstick with the closest length one
        if (arr[i + 1] - arr[i] <= D)
        {
            i = i + 2;
            pairs++;
        }
        else
        {
            i++;
        }
    }

    cout << pairs;
}