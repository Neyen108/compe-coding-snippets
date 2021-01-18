#include <iostream>

using namespace std;

int main()
{
    //test cases
    int t;
    cin >> t;
    while (t--)
    {
        //size of array
        int n;
        cin >> n;

        int arr[n];

        //prefix sum of frequency odd numbers
        int prefix[n];

        //take the first number
        cin >> arr[0];

        //count of even prefix sum
        long long int count = 0;

        //initialize prefix sum
        prefix[0] = 0;

        //if the first number is odd
        //increment prefix[0]
        if (arr[0] & 1)
        {
            prefix[0]++;
        }
        //if it is even
        else
        {
            count++;
        }

        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            prefix[i] = prefix[i - 1];

            //if the no is odd
            //increment prefix count of odd numbers
            if (arr[i] & 1)
            {
                prefix[i]++;
            }

            //if the subarray from 0 to i has even number of odd nos
            if (prefix[i] % 2 == 0)
            {
                count++;
            }
        }
        //hahndshaking lemma
        //answer = even + evenC2 + oddC2
        cout << count + (count * (count - 1) / 2) + ((n - count) * (n - count - 1) / 2) << endl;
    }
}