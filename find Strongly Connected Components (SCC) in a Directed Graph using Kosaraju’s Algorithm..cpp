#include <iostream>
using namespace std;

#define V 5  // Number of vertices

void dfs(int v, bool visited[], int graph[V][V], int stack[], int &top) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i, visited, graph, stack, top);
    }
    stack[++top] = v;  // push to stack
}

void dfsUtil(int v, bool visited[], int graph[V][V]) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i])
            dfsUtil(i, visited, graph);
    }
}

void transposeGraph(int graph[V][V], int transpose[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            transpose[i][j] = graph[j][i];
}

void findSCCs(int graph[V][V]) {
    bool visited[V] = {false};
    int stack[V], top = -1;

    // Step 1: Fill vertices in stack according to their finishing time
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, visited, graph, stack, top);

    // Step 2: Create the transpose of the graph
    int transpose[V][V] = {0};
    transposeGraph(graph, transpose);

    // Step 3: Do DFS on transposed graph in order of stack
    for (int i = 0; i < V; i++) visited[i] = false;

    cout << "Strongly Connected Components:\n";
    while (top >= 0) {
        int v = stack[top--];
        if (!visited[v]) {
            dfsUtil(v, visited, transpose);
            cout << endl;
        }
    }
}

int main() {
    // Example directed graph with SCCs
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    findSCCs(graph);

    return 0;
}
