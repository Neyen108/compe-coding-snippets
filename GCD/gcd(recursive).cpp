#include <iostream>
using namespace std;

//time complexity of gcd algo is LogN
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, (a % b));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}