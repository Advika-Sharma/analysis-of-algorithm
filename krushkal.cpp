#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int src, dest, weight;
};
class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
bool compare(const Edge &a, const Edge &b) {
    return a.weight < b.weight; 
}
vector<Edge> kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare); 
    DisjointSet ds(n);
    vector<Edge> mst;
    for (const Edge &e : edges) {
        if (ds.find(e.src) != ds.find(e.dest)) {
            ds.unionSet(e.src, e.dest); 
            mst.push_back(e); 
        }
    }
    return mst;
}
int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    vector<Edge> mst = kruskal(n, edges);
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge &e : mst) {
        cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
    }
    return 0;
}


//int n = 4;  // Number of vertices
//vector<Edge> edges = {
  //  {0, 1, 10},  // Edge from 0 to 1 with weight 10
   // {0, 2, 6},   // Edge from 0 to 2 with weight 6
    //{0, 3, 5},   // Edge from 0 to 3 with weight 5
    //{1, 3, 15},  // Edge from 1 to 3 with weight 15
    //{2, 3, 4}    // Edge from 2 to 3 with weight 4
//};
