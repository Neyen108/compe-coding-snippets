#include <iostream>

using namespace std;

bool isSorted(int a[], int n)
{
    //if size of array is 0 or 1, i.e. an array of size 1 is always sorted
    if (n == 0 || n == 1)
    {
        return true;
    }

    //if a[0] < a[1] and the array from a+1 is sorted
    if ((a[0] < a[1]) && isSorted(a + 1, n - 1))
    {
        return true;
    }
    return false;
}