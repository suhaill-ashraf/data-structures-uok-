#include <iostream>
using namespace std;

#define V 4

bool dfs(int v, int graph[V][V], bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(i, graph, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false; // remove the vertex from recursion stack
    return false;
}

bool isCyclic(int graph[V][V]) {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (dfs(i, graph, visited, recStack))
                return true;

    return false;
}

int main() {
    // Example with a cycle: 0 ? 1 ? 2 ? 0
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if (isCyclic(graph))
        cout << "Cycle detected in the directed graph.\n";
    else
        cout << "No cycle in the directed graph.\n";

    return 0;
}
