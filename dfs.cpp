#include <iostream>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int Adj2[100][100];  // adjacency list
int deg2[100];
int color2[100], pi2[100], d2[100], f2[100];
int Time;

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
