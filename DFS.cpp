#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(graph, visited, neighbor);
        }
    }
}

bool isConnected(const vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    DFS(graph, visited, 0);  // Start DFS from node 0

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;  // If any node is not visited, the graph is not connected
        }
    }
    return true;  // All nodes are visited, so the graph is connected
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // For undirected graph
    }

    if (isConnected(graph, V)) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }

    return 0;
}


//5 4
//0 1
//0 2
//1 3
//3 4
