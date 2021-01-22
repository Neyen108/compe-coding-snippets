#include <bits/stdc++.h>

using namespace std;

string spelling[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

//f(156) -> f(15) -> f(1) -> f(0)

//printSpelling(2048)
void printSpelling(int n)
{
    if (n == 0)
    {
        return;
    }

    //printSpelling(204)
    // 8 is left
    printSpelling(n / 10);

    //here comes 8
    cout << spelling[n % 10] << " ";
}

//bottom to top

int main()
{
    printSpelling(2048);
}