#include <iostream>

using namespace std;

int lastOccurence(int *a, int n, int key)
{
    //base case
    if (n == 0)
    {
        return -1;
    }

    //go down till the last
    int pos = lastOccurence(a + 1, n - 1, key);

    if (pos == -1)
    {
        //if we find the key
        if (a[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    //in the bigger array the position of key will be pos+1
    return pos + 1;
}

int main()
{
    int arr[] = {4, 7, 2, 8, 5, 6, 9, 7, 2};
    int n = 9;
    cout << lastOccurence(arr, n, 7);
}