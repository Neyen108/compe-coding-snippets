//846-B

#include <iostream>
using namespace std;

int main()
{
    int ans[1000001] = {0};
    int last_occ[1000001] = {0};

    int n;
    cin >> n;
    int no;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> no;
        ans[i] = ans[i - 1] + i - last_occ[no];
        last_occ[no] = i;
        sum = sum + ans[i];
    }

    double result = ((2 * (sum - n) + n) * 1.0) / (n * n * 1.0);

    cout << result;
}