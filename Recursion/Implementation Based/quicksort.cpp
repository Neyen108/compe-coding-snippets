#include <bits/stdc++.h>

using namespace std;

int partition(int *a, int start, int end)
{
    int pivot = end;
    int i = start - 1; //smaller part
    int j = start;     //bigger part

    for (j = start; j < end; j++)
    {
        if (a[j] <= a[pivot]) //if we encounter a smaller element
        {
            i++;              //increase the smaller region
            swap(a[i], a[j]); //swap the bigger number there with the smaller part
        }
    }

    swap(a[i + 1], a[pivot]); //the correct position

    return i + 1; //the correct position is returned
}

void quicksort(int *a, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = partition(a, start, end);
    quicksort(a, start, p - 1);
    quicksort(a, p + 1, end);
}

int main()
{
    int arr[] = {4, 7, 2, 8, 5, 6, 9, 7, 2};
    int start = 0;
    int end = 8;
    quicksort(arr, start, end);
    for (int a : arr)
    {
        cout << a << " ";
    }
}