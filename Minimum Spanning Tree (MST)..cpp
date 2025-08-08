#include <iostream>
using namespace std;

#define V 5
#define E 7  // Number of edges

struct Edge {
    int src, dest, weight;
};

void sortEdges(Edge edges[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST(Edge edges[], int v, int e) {
    sortEdges(edges, e);

    Edge result[10];  // Set a reasonable upper limit for result[] size
    int parent[V], rank[V] = {0};

    for (int i = 0; i < v; i++)
        parent[i] = i;

    int edgeCount = 0, i = 0;
    while (edgeCount < v - 1 && i < e) {
        Edge next = edges[i++];
        int x = find(parent, next.src);
        int y = find(parent, next.dest);

        if (x != y) {
            result[edgeCount++] = next;
            unionSets(parent, rank, x, y);
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n";
    for (int i = 0; i < edgeCount; i++)
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
}

int main() {
    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {1, 2, 25},
        {3, 4, 2}
    };

    kruskalMST(edges, V, E);
    return 0;
}
