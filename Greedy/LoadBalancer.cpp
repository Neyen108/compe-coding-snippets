#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //no of preocessors
        int n;
        cin >> n;

        int sum = 0; //sum of all loads or work
        int arr[n];  //load of processors
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        //if load cannot be equally divided, then --> not possible
        if (sum % n != 0)
        {
            cout << -1 << "\n";
            continue;
        }

        //final load of the processors
        int finalLoad = sum / n;

        int cumulativeSum = 0;
        int finalLoadSum = 0;
        int maxTransfer = 0;

        for (int i = 0; i < n; i++)
        {
            cumulativeSum += arr[i];   //sum of the loads till the position
            finalLoadSum += finalLoad; //final loads sum till the position, if all is divided equally
            int loadTransfer = abs(finalLoadSum - cumulativeSum);

            if (loadTransfer > maxTransfer)
            {
                maxTransfer = loadTransfer;
            }
        }

        cout << maxTransfer << "\n";
    }
}