#include <iostream>
using namespace std;

#define V 6

void topologicalSortUtil(int v, bool visited[], int graph[V][V], int stack[], int &top) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i])
            topologicalSortUtil(i, visited, graph, stack, top);
    }

    stack[++top] = v;  // Push to stack
}

void topologicalSort(int graph[V][V]) {
    bool visited[V] = {false};
    int stack[V], top = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, graph, stack, top);

    cout << "Topological Sort (Order of tasks): ";
    while (top >= 0)
        cout << stack[top--] << " ";
    cout << endl;
}

int main() {
    // Adjacency matrix for a DAG
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph);

    return 0;
}
