#include <bits/stdc++.h>
using namespace std;

class RsAllGra {
private:
    int nodeCount;
    char nodeLabels[100];
    int matrix[100][100];

    int getNodeIndex(char node);
    bool dfs(int node, bool visited[], bool inStack[]);

public:
    RsAllGra();
    void addNode(char node);
    void addEdge(char a, char z);
    bool detectDeadlock();
};

RsAllGra::RsAllGra() {
    nodeCount = 0;
    memset(matrix, 0, sizeof(matrix));
}

int RsAllGra::getNodeIndex(char node) {
    for (int i = 0; i < nodeCount; i++) {
        if (nodeLabels[i] == node)
            return i;
    }
    return -1;
}

void RsAllGra::addNode(char node) {
    if (getNodeIndex(node) == -1) {
        nodeLabels[nodeCount++] = node;
    }
}

void RsAllGra::addEdge(char a, char z) {
    addNode(a);
    addNode(z);
    int from = getNodeIndex(a);
    int to = getNodeIndex(z);
    matrix[from][to] = 1;
}

// DFS to detect cycles
bool RsAllGra::dfs(int node, bool visited[], bool inStack[]) {
    visited[node] = true;
    inStack[node] = true;

    for (int i = 0; i < nodeCount; i++) {
        if (matrix[node][i] == 1) {
            if (!visited[i] && dfs(i, visited, inStack))
                return true;
            else if (inStack[i])
                return true;
        }
    }

    inStack[node] = false;
    return false;
}

bool RsAllGra::detectDeadlock() {
    bool visited[100] = {false};
    bool inStack[100] = {false};

    for (int i = 0; i < nodeCount; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, inStack))
                return true;
        }
    }

    return false;
}

int main() {
    RsAllGra rag;

    int numNodes, numEdges;
    cout << "Number of Nodes: ";
    cin >> numNodes;

    cout << "Number of Edges: ";
    cin >> numEdges;

    cout << "Enter Edges:\n";
    for (int i = 0; i < numEdges; i++) {
        char a, z;
        cin >> a >> z;
        rag.addEdge(a, z);
    }

    if (rag.detectDeadlock())
        cout << "Deadlock: Yes" << endl;
    else
        cout << "Deadlock: No" << endl;

    return 0;
}
