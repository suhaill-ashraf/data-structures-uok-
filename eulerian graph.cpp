#include <iostream>
using namespace std;

#define V 5

void addEdge(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void DFS(int graph[V][V], bool visited[], int v) {
    visited[v] = true;
    for (int i = 0; i < V; i++)
        if (graph[v][i] && !visited[i])
            DFS(graph, visited, i);
}

bool isConnected(int graph[V][V]) {
    bool visited[V] = {false};

    int i;
    for (i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++)
            degree += graph[i][j];
        if (degree > 0)
            break;
    }

    if (i == V)
        return true;

    DFS(graph, visited, i);

    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++)
            degree += graph[i][j];
        if (degree > 0 && !visited[i])
            return false;
    }

    return true;
}

bool isEulerGraph(int graph[V][V]) {
    if (!isConnected(graph))
        return false;

    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++)
            degree += graph[i][j];
        if (degree % 2 != 0)
            return false;
    }

    return true;
}

int main() {
    int graph[V][V] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    if (isEulerGraph(graph))
        cout << "The graph is an Euler Graph.\n";
    else
        cout << "The graph is NOT an Euler Graph.\n";

    return 0;
}
