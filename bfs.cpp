#include <iostream>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int Adj[100][100]; // adjacency list stored as matrix
int deg[100];      // degree of each vertex

void BFS(int s, int V)
{
    int color[100], d[100], pi[100];
    int Q[1000], head = 0, tail = 0;

    // Initialize
    for (int i = 0; i < V; i++)
    {
        color[i] = WHITE;
        d[i] = 1000000000; // INF
        pi[i] = -1;
    }

    color[s] = GRAY;
    d[s] = 0;
    pi[s] = -1;

    // Enqueue source
    Q[tail++] = s;

    // BFS loop
    while (head < tail)
    {
        int u = Q[head++];

        for (int i = 0; i < deg[u]; i++)
        {
            int v = Adj[u][i];

            if (color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                pi[v] = u;
                Q[tail++] = v;
            }
        }

        color[u] = BLACK;
    }

    // Print BFS result
    cout << "\nBFS distances:\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " : " << d[i] << "\n";
}
