#include <bits/stdc++.h>

using namespace std;

bool ratInAMaze(char maze[10][10], int sol[][10], int rows, int cols, int i, int j)
{
    //base case
    if (i == rows && j == cols)
    {
        sol[i][j] = 1;
        //print path
        for (int m = 0; m <= rows; m++)
        {
            for (int n = 0; n <= cols; n++)
            {
                cout << sol[m][n] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        //return true
        return true;
    }

    //if we go outside the maze
    if (i > rows || j > cols)
    {
        return false;
    }

    //if blocked
    if (maze[i][j] == 'X')
    {
        return false;
    }

    //if the box is valid
    sol[i][j] = 1;
    //recursion
    bool checkRight = ratInAMaze(maze, sol, rows, cols, i, j + 1);
    bool checkDown = ratInAMaze(maze, sol, rows, cols, i + 1, j);

    //after recursion is complete, and path is printed, or path is blocked, backtrack
    sol[i][j] = 0;

    if (checkDown || checkRight) //if we can go down or right, and get the path; return true
    {
        return true;
    }
    return false;
}

int main()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"};

    int sol[10][10] = {0};

    int rows = 4;
    int cols = 4;
    if (!ratInAMaze(maze, sol, rows - 1, cols - 1, 0, 0))
    {
        cout << "No path Exists" << endl;
    }
}

//to see the count of paths
//just include a pass by reference of count