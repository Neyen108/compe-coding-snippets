#include <bits/stdc++.h>

using namespace std;

bool isSafe(int mat[][9], int n, int i, int j, int number)
{
    //check the row and column
    for (int x = 0; x < n; x++)
    {
        if ((mat[i][x] == number) || (mat[x][j] == number))
        {
            return false;
        }
    }

    //check subrgrid

    int root_n = sqrt(n);

    //subgrid start coordinates
    int sx = (i / root_n) * root_n;
    int sy = (j / root_n) * root_n;

    for (int row = sx; row < (sx + root_n); row++)
    {
        for (int col = sy; col < (sy + root_n); col++)
        {
            if (mat[row][col] == number)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int mat[][9], int n, int i, int j)
{
    //base case
    //if all the rows have been filled
    if (i == n)
    {
        //print matrix
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << mat[row][col] << " ";
            }
            cout << '\n';
        }
        cout << "\n";
        //true (solved)
        return true;
    }

    //if we reach the end of row
    if (j == n)
    {
        //go to the next row (i+1)(0)
        return sudokuSolver(mat, n, i + 1, 0);
    }

    //if already filled then skip
    if (mat[i][j] != 0)
    {
        return sudokuSolver(mat, n, i, j + 1);
    }

    //fill the current box with all the values
    for (int number = 1; number <= n; number++)
    {
        if (isSafe(mat, n, i, j, number))
        {
            //if safe to put number, then put number
            mat[i][j] = number;

            //can the remaining part of the sudoku be solved.... if we put number at mat[i][j]
            bool couldBeSolved = sudokuSolver(mat, n, i, j + 1);

            if (couldBeSolved) //if the remaining part of the sudoku can be solved, return true
            {
                return true;
            }
            // if "cannot be solved" then loop will continue, with a different number
        }
    }

    //if all the numbers(1->n) have been tested (loop ended and we are here) and still the sudoku could not be solved
    //backtrack
    mat[i][j] = 0;
    return false;
}

int main()
{
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    int n = 9;
    sudokuSolver(mat, n, 0, 0);
}