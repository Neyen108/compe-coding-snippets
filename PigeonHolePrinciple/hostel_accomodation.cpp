#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
    int V;                   // no of vertices
    list<pair<int, int>> *l; //list to hold the destination & cost

    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int source, int destination, int cost)
    {
        //bi-directional
        // l[vertex] = (destination, egde weight)

        l[source].push_back(make_pair(destination, cost));
        l[destination].push_back(make_pair(source, cost));
    }

    int dfs_helper(int node, bool *visited, int *count, int &ans)
    {
        visited[node] = true; //node is now visited
        count[node] = 1;      //count of that node is initially 1, the node itself

        //iterate through the neighbours of l[node]
        for (pair<int, int> p : l[node]) //l[2]
        {

            int nbr = p.first;      //nbr node
            int edge_wt = p.second; //weight of that edge

            //if nbr is not visited
            if (!visited[nbr])
            {
                //go to nbr and find the count of the nodes there
                count[node] = count[node] + dfs_helper(nbr, visited, count, ans);

                //no. of nodes on right side
                int right = count[nbr];
                //no. of nodes on left side
                int left = V - right;
                //add the contibution
                ans = ans + (2 * min(right, left) * edge_wt);
            }
        }

        return count[node];
    }

    int dfs()
    {
        //visited array, intitially all are unvisited
        bool *visited = new bool[V]{0};

        //to store the no. of nodes of subtree
        int *count = new int[V]{0};

        int ans = 0;

        //helper function to calculate the distance recursively
        dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    cout << g.dfs();
}