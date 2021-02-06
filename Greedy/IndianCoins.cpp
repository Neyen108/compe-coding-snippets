#include <bits/stdc++.h>

using namespace std;

int coinsNeeded(int coins[], int n, int amount)
{
    int ans = 0;
    while (amount > 0)
    {
        //find the note closest to amount;
        int idx = upper_bound(coins, coins + n, amount) - 1 - coins;

        //find how many notes can be used to create that amount or (closest to the amount)
        ans = ans + (amount / coins[idx]);

        //remainder will be used for other notes
        amount = amount % coins[idx];
    }

    return ans;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    int money;
    cin >> money;

    cout << coinsNeeded(coins, 10, money);
}