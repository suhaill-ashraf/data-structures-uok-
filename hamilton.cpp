#include <iostream>
using namespace std;

#define V 5

bool isSafe(int v, int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1; // backtrack
        }
    }

    return false;
}

bool hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists.\n";
        return false;
    }

    cout << "Hamiltonian Cycle exists: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl; // Complete the cycle
    return true;
}

int main() {
    int graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph1);

    return 0;
}
