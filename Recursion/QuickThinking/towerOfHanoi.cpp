#include <bits/stdc++.h>

using namespace std;

void towerHanoi(int n, char src, char helper, char dest)
{
    //if there are no disks return
    if (n == 0)
    {
        return;
    }

    towerHanoi(n - 1, src, dest, helper);
    cout << "Disk " << n << " moved from " << src << " to" << dest << "\n";
    towerHanoi(n - 1, helper, src, dest);
}

int main()
{
    towerHanoi(3, 'A', 'B', 'C');
}