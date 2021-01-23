#include <bits/stdc++.h>

using namespace std;

bool isSafe(int chessboard[][100], int n, int i, int j)
{
    //check the column
    for (int row = 0; row < n; row++)
    {
        if (chessboard[row][j] == 1)
        {
            return false;
        }
    }

    //check left upper diagonal
    int row = i;
    int col = j;
    while (row >= 0 && col >= 0)
    {
        if (chessboard[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    //check right upper diagonal
    row = i;
    col = j;

    while (row >= 0 && col < n)
    {
        if (chessboard[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool Nqueens(int chessboard[][100], int n, int i)
{
    //base case
    if (i == n)
    {
        //print chessboard
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (chessboard[row][col] == 1)
                {
                    cout << "Q ";
                }
                cout << "_ ";
            }
            cout << "\n";
        }
        cout << "\n";
        return false;
    }

    //place queen in the row
    for (int j = 0; j < n; j++)
    {
        if (isSafe(chessboard, n, i, j))
        {
            //if safe put the queen there
            chessboard[i][j] = 1;
            bool nextQueen = Nqueens(chessboard, n, i + 1);

            if (nextQueen)
            {
                return true;
            }
            //if next queen cannot be placed
            //remove the queen and go forward
            chessboard[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int chessboard[100][100] = {0};

    Nqueens(chessboard, n, 0);
}