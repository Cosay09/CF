#include <iostream>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int Adj2[100][100];  // adjacency list
int deg2[100];
int color2[100], pi2[100], d2[100], f2[100];
int Time;

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Reset degrees
    for (int i = 0; i < V; i++)
        deg[i] = deg2[i] = 0;

    cout << "Enter each edge as: u v\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        Adj[u][deg[u]++] = v;   // for BFS
        Adj2[u][deg2[u]++] = v; // for DFS
    }

    int start;
    cout << "Enter BFS start vertex: ";
    cin >> start;

    BFS(start, V);
    DFS(V);

    return 0;
}


void DFS_VISIT(int u)
{
    Time++;
    d2[u] = Time;
    color2[u] = GRAY;

    for (int i = 0; i < deg2[u]; i++)
    {
        int v = Adj2[u][i];
        if (color2[v] == WHITE)
        {
            pi2[v] = u;
            DFS_VISIT(v);
        }
    }

    color2[u] = BLACK;
    Time++;
    f2[u] = Time;
}

void DFS(int V)
{
    for (int i = 0; i < V; i++)
    {
        color2[i] = WHITE;
        pi2[i] = -1;
    }

    Time = 0;

    for (int u = 0; u < V; u++)
        if (color2[u] == WHITE)
            DFS_VISIT(u);

    cout << "\nDFS discovery and finish times:\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " : d=" << d2[i] << ", f=" << f2[i] << "\n";
}
