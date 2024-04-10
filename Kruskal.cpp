#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

int findParent(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

void kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V, -1);

    for (auto edge : edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            result.push_back(edge);
            unionSets(parent, x, y);
        }
    }
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskalMST(edges, V);

    return 0;
}