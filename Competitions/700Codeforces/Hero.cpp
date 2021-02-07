#include <bits/stdc++.h>

using namespace std;

struct attack_health
{
    int attack;
    int health;
};

bool compare(attack_health m1, attack_health m2)
{
    return m1.attack < m2.attack;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int A;
        long long int B;
        int n;

        cin >> A >> B >> n;

        vector<attack_health> ab(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ab[i].attack;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> ab[i].health;
        }

        sort(ab.begin(), ab.end(), compare);

        int i = 0;

        for (i = 0; i < n; i++)
        {
            while (ab[i].health > 0)
            {
                if (B <= 0)
                {
                    break;
                }

                ab[i].health -= A;

                B -= ab[i].attack;
            }

            if (ab[i].health > 0)
            {
                break;
            }
        }

        if (i == n)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}