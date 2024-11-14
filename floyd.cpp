#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency matrix (use 0 for no edge, and positive numbers for weights):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    floydWarshall(graph, V);
    return 0;
}


//Enter the number of vertices: 4
//Enter the adjacency matrix (use 0 for no edge, and positive numbers for weights):
//0 3 0 0
//3 0 1 0
//0 1 0 7
//0 0 7 0
