#include <iostream>

using namespace std;

int modInverse(int a, int m)
{
    if (m == 1)
        return 0;

    int m0 = m, y = 0, x = 1;

    while (a > 1)
    {
        int q = a / m, t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    int nums[3] = {2, 3, 7};
    int rems[3] = {1, 2, 5};

    int pp[3];
    int inverse[3];

    int product = 1;
    for (int i = 0; i < 3; i++)
    {
        product *= nums[i];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        pp[i] = product / nums[i];
        inverse[i] = modInverse(pp[i], nums[i]);
        ans = (pp[i] * rems[i] * inverse[i]) % product;
    }

    cout << ans % product;
}