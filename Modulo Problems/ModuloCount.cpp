#include <iostream>
using namespace std;

long long int solve(long long int l, long long int r, int a, int b)
{

    int n = a * b; //size of the sub-array 0 ---> a*b - 1
    int arr[n];

    int count = 0; //counts the no. of such x's from 0 to (a*b-1)
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
        //mark the x's and keep their count
        if (((i % a) % b) != ((i % b) % a))
        {
            arr[i] = 1;
            count++;
        }
    }

    //the part of r which remains after r/ab
    int right_count = 0;
    for (int i = 0; i <= (r % (a * b)); i++)
    {
        //count such x's
        if (arr[i] == 1)
        {
            right_count++;
        }
    }

    //the part of l-1 which remains after l-1/ab
    int left_count = 0;
    for (int i = 0; i <= ((l - 1) % (a * b)); i++)
    {
        //count such x's
        if (arr[i] == 1)
        {
            left_count++;
        }
    }

    //all x's till r
    long long int right = ((r / (a * b)) * count) + right_count;

    //all x's till l-1
    long long int left = (((l - 1) / (a * b)) * count) + left_count;

    return right - left;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, q;
        cin >> a >> b >> q;

        long long int l, r;

        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            cout << solve(l, r, a, b) << " ";
        }
        cout << endl;
    }
}