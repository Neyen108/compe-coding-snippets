#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        int starirs = (x - 1) * 20;

        int elevator = ((y - 1) * 5) + ((x - 1) * 5);

        cout << min(starirs, elevator) << "\n";
    }
}