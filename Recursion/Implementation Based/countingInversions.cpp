#include <iostream>

using namespace std;

int merge(int *a, int start, int end)
{
    int mid = (start + end) / 2;

    int i = start;
    int j = mid + 1;

    int inversionCount = 0;

    int temp[100];
    int k = 0;
    while (i <= mid && j <= end)
    {
        //if a[i] > a[j].. then no. of elements greater than a[j] will be mid-i+1 (as they are sorted)
        if (a[i] > a[j])
        {
            inversionCount += (mid - i + 1);
            temp[k] = a[j];
            k++;
            j++;
        }
        else
        {
            temp[k] = a[i];
            i++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }

    //copy the sorted array

    for (int i = 0; i < k; i++)
    {
        a[start + i] = temp[i];
    }

    return inversionCount;
}

//exactly like merge-sort
int CountInversions(int *a, int start, int end)
{
    //base case
    //if only one element is considered, then there are no inversions
    if (start >= end)
    {
        return 0;
    }

    int mid = (start + end) / 2;

    //inversions in left
    int left = CountInversions(a, start, mid);
    //inversions in rigth
    int right = CountInversions(a, mid + 1, end);
    //inversions in middle
    int middle = merge(a, start, end);

    return left + right + middle;
}

int main()
{
    int a[] = {1, 5, 2, 6, 3, 0};
    cout << CountInversions(a, 0, 5);
}