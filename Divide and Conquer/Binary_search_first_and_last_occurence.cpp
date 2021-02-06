#include <bits/stdc++.h>

using namespace std;

int firstOccurence(int a[], int l, int r, int num, int pos)
{
    if (l > r)
    {
        return pos;
    }

    int mid = (l + r) / 2;

    if (a[mid] == num)
    {
        r = mid - 1; //since first occurence, therefore towards left
        pos = firstOccurence(a, l, r, num, mid);
    }
    else if (num < a[mid])
    {
        r = mid - 1;
        pos = firstOccurence(a, l, r, num, pos);
    }
    else
    {
        l = mid + 1;
        pos = firstOccurence(a, l, r, num, pos);
    }
    return pos;
}

int lastOccurence(int a[], int l, int r, int key, int pos)
{
    //base case
    if (l > r)
    {
        return pos;
    }

    int mid = (l + r) / 2;

    if (a[mid] == key)
    {
        l = mid + 1; //last occurence, so look right
        pos = lastOccurence(a, l, r, key, mid);
    }
    else if (key < a[mid])
    {
        r = mid - 1;
        pos = lastOccurence(a, l, r, key, pos);
    }
    else
    {
        l = mid + 1;
        pos = lastOccurence(a, l, r, key, pos);
    }
    return pos;
}

int main()
{
    int a[] = {3, 4, 6, 7, 7, 7, 7, 9, 11, 23};
    cout << firstOccurence(a, 0, 9, 7, -1) << "\n";
    cout << lastOccurence(a, 0, 9, 7, -1);
}