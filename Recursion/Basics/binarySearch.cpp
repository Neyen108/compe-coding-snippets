#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int key)
{

    if (l > r)
    {
        return -1;
    }

    int mid = (l + r) / 2;
    if (a[mid] > key)
    {
        return binarySearch(a, l, mid - 1, key);
    }
    else if (key > a[mid])
    {
        return binarySearch(a, mid + 1, r, key);
    }
    else
    {
        return a[mid];
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 9};
    cout << binarySearch(a, 0, 7, 4);
}

//top to bottom