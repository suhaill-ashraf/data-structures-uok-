#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u])
            DFSUtil(u, adj, visited);
    }
}

void DFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(i, adj, visited);
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {3};

    DFS(V, adj);

    return 0;
}
