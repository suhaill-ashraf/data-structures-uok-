#include <iostream>
using namespace std;

#define V 5  // Number of vertices

bool dfs(int v, int parent, bool visited[], int graph[V][V]) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v, visited, graph))
                    return true;
            } else if (i != parent) {
                return true;  // A back edge found
            }
        }
    }

    return false;
}

bool hasCycle(int graph[V][V]) {
    bool visited[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, graph))
                return true;
        }
    }

    return false;
}

int main() {
    // Example graph with a cycle
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    if (hasCycle(graph))
        cout << "Cycle detected in the undirected graph.\n";
    else
        cout << "No cycle in the undirected graph.\n";

    return 0;
}
