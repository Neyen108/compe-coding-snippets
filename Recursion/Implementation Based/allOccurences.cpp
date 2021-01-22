#include <iostream>

using namespace std;

int allOccurenecs(int *a, int i, int n, int key, int *output, int j)
{
    //if we reach the end
    //base case
    if (i == n)
    {
        return j;
    }

    if (a[i] == key)
    {
        output[j] = i;
        //increment j
        return allOccurenecs(a, i + 1, n, key, output, j + 1);
    }

    return allOccurenecs(a, i + 1, n, key, output, j);
}

int main()
{
    int arr[] = {4, 7, 2, 8, 5, 6, 9, 7, 2};
    int n = 9;
    int output[100];
    cout << allOccurenecs(arr, 0, n, 7, output, 0);
}