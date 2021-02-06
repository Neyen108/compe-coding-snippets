#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //dimensions of board
        int board_x, board_y;
        cin >> board_x >> board_y;

        int towers;
        cin >> towers;

        //positions of towers
        int x[towers], y[towers];

        for (int i = 0; i < towers; i++)
        {
            cin >> x[i] >> y[i];
        }

        sort(x, x + towers);
        sort(y, y + towers);

        //undefended from the start of board
        int delta_x = abs(x[0] - 1);
        int delta_y = abs(y[0] - 1);

        //to hold the max undefended stretches
        int max_x = delta_x;
        int max_y = delta_y;

        //find the undefended stretches
        for (int i = 1; i < towers; i++)
        {
            delta_x = abs(x[i] - (x[i - 1] + 1));
            delta_y = abs(y[i] - (y[i - 1] + 1));

            if (delta_x > max_x)
            {
                max_x = delta_x;
            }
            if (delta_y > max_y)
            {
                max_y = delta_y;
            }
        }

        //undefended stretch from the end of board
        delta_x = abs(board_x - x[towers - 1]);
        delta_y = abs(board_y - y[towers - 1]);

        if (delta_x > max_x)
        {
            max_x = delta_x;
        }
        if (delta_y > max_y)
        {
            max_y = delta_y;
        }

        cout << max_x * max_y;
    }
}