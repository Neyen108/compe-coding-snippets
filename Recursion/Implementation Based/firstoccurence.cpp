#include <iostream>

using namespace std;

int firstOccurence(int *a, int n, int key)
{
    //if we reach the end
    //i.e. element is not present
    if (n == 0)
    {
        return -1;
    }

    //if key is found
    if (a[0] == key)
    {
        return 0;
    }

    //recursive call
    int pos = firstOccurence(a + 1, n - 1, key);
    //if still not found
    if (pos == -1)
    {
        return -1;
    }

    //pos + 1 because of the relative position
    return pos + 1;
}

int linearSearch(int *a, int i, int n, int key)
{
    //if we reach the end, and the key still hasnt been found
    if (i == n)
    {
        return -1;
    }

    //if the key is found
    if (a[i] == key)
    {
        return i;
    }

    return linearSearch(a, i + 1, n, key);
}

int main()
{
    int arr[] = {4, 7, 2, 8, 5, 6, 9, 7, 2};
    int n = 9;
    cout << firstOccurence(arr, n, 2) << " " << linearSearch(arr, 0, n, 7);
}