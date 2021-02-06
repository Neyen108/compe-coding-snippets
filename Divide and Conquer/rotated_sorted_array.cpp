#include <bits/stdc++.h>

using namespace std;

int findPivot(int a[], int n, int key)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == key)
        {
            return key;
        }
        else if (a[l] <= a[mid])
        {
            if (key >= a[l] && key < a[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (key <= a[r] && key > a[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int a[] = {4, 5, 6, 7, 1, 2, 3};
    cout << findPivot(a, 7, 6);
}