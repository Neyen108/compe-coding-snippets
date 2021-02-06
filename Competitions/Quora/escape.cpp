#include <bits/stdc++.h>
using namespace std;

int maze[1003][1003];

int n, m, k;

bool isValid(int i, int j, int n, int m)
{
    if ((i < 0 || i >= n) || (j < 0 || j >= m))
    {
        return false;
    }
    return true;
}

int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};

struct queueNode
{
    int i, j, moves;
};

struct point
{
    int x, y;
};

int BFS(int mat[][1003], point src, point dest)
{
    if (mat[src.x][src.y] == 1 || mat[dest.x][dest.y] == 1)
        return -1;

    bool visited[n][m];
    memset(visited, false, sizeof visited);

    visited[src.x][src.y] = true;

    queue<queueNode> q;

    queueNode s = {src.x, src.y, 0};
    q.push(s);

    while (!q.empty())
    {
        queueNode curr = q.front();
        point pt = {curr.i, curr.j};

        if (pt.x == dest.x && pt.y == dest.y)
            return curr.moves;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row1 = pt.x + row[i];
            int col1 = pt.y + col[i];

            if (isValid(row1, col1, n, m) && (mat[row1][col1] == 0) &&
                !visited[row1][col1])
            {

                visited[row1][col1] = true;
                queueNode Adjcell = {row1, col1, curr.moves + 1};
                q.push(Adjcell);
            }
        }
    }

    return -1;
}

int main()
{

    cin >> n >> m >> k;
    char ch;

    point start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            if (ch == '.')
            {
                maze[i][j] = 0;
            }
            else if (ch == '#')
            {
                maze[i][j] = 1;
            }
            else if (ch == 'S')
            {
                start.x = i;
                start.y = j;
            }
            else if (ch == 'E')
            {
                end.x = i;
                end.y = j;
            }
        }
    }

    //guards
    int r, c, d;

    queue<queueNode> q;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> d;
        maze[r - 1][c - 1] = 1;
        queueNode guard = {r - 1, c - 1, d};
        q.push(guard);
    }

    //bfs for the guards
    while (!q.empty())
    {
        queueNode curr = q.front();
        int x = curr.i;
        int y = curr.j;
        int moves = curr.moves;

        if (moves > 0)
        {
            for (int i = 0; i < 4; i++)
            {
                if (isValid(x + row[i], y + col[i], n, m))
                {
                    if (maze[x + row[i]][y + col[i]] != 1)
                    {
                        maze[x + row[i]][y + col[i]] = 1;

                        if (moves - 1 > 0)
                        {
                            queueNode guard = {x + row[i], y + col[i], moves - 1};
                            q.push(guard);
                        }
                    }
                }
            }
        }

        q.pop();
    }

    int dist = BFS(maze, start, end);

    if (dist == -1)
    {
        cout << "IMPOSSIBLE"
             << "\n";
    }
    else
    {
        cout << dist << "\n";
    }
}