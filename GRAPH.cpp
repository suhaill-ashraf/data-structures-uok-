#include <iostream>
#include <vector>
using namespace std;

void adjacencyMatrix(int V, vector<pair<int, int>> edges) {
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (auto e : edges) {
        matrix[e.first][e.second] = 1;
        matrix[e.second][e.first] = 1;
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void adjacencyList(int V, vector<pair<int, int>> edges) {
    vector<vector<int>> adj(V);
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j : adj[i])
            cout << j << " ";
        cout << endl;
    }
}

void edgeList(vector<pair<int, int>> edges) {
    cout << "\nEdge List:\n";
    for (auto e : edges)
        cout << "(" << e.first << ", " << e.second << ")\n";
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}
    };

    adjacencyMatrix(V, edges);
    adjacencyList(V, edges);
    edgeList(edges);

    return 0;
}
