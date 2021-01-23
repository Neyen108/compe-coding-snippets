#include <iostream>

using namespace std;

string getMax(int a, int b)
{
    if ((a > 0 && b > 0) || (a < 0 && b < 0) || (a < 0 && b == 0))
    {
        return "*";
    }
    else if ((a > 0 && b == 0) || (a == 0 && b > 0) || (a == 0 && b == 0))
    {
        return "+";
    }
    else if ((a > 0 && b < 0) || (a == 0 && b < 0))
    {
        return "-";
    }

    else
    {
        int x = a + b;
        int y = a / b;
        if (x > y)
        {
            return "+";
        }
        return " \ ";
    }
}

int main()
{
    cout << getMax(7, -7);
}