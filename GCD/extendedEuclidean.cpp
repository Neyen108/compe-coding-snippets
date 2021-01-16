#include <iostream>

using namespace std;

int X, Y, GCD;
void extendedEuclidean(int a, int b)
{
    //base case
    //if b reaches 0, then GCD is found
    if (b == 0)
    {
        GCD = a;
        X = 1;
        Y = 0;
        return; //return after updating the values
    }

    //call the extended euclidean recursively
    extendedEuclidean(b, a % b);

    //bottom - up
    int currX = Y;
    int currY = X - ((a / b) * Y);

    //update the values
    X = currX;
    Y = currY;
}

int main()
{
    int a, b;
    cin >> a >> b;
    extendedEuclidean(a, b);
    cout << X << ", " << Y;
}