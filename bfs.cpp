#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& graph, int start, int V) {
    vector<bool> visited(V, false);  // To keep track of visited nodes
    queue<int> q;  // Queue for BFS

    visited[start] = true;  // Mark the start node as visited
    q.push(start);  // Start BFS from the given start node

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Print the current node

        // Explore all neighbors of the current node
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;  // Mark as visited
                q.push(neighbor);  // Add to the queue
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    cout << "Enter the number of edges (E): ";
    cin >> E;

    // Create an adjacency list for the graph
    vector<vector<int>> graph(V);

    cout << "Enter the edges (from to):\n";
    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);  // Add directed edge from 'from' to 'to'
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    cout << "Nodes reachable from " << start << " using BFS: ";
    BFS(graph, start, V);

    return 0;
}
//Enter the number of vertices (V): 6
//Enter the number of edges (E): 7
//Enter the edges (from to):
//0 1
//0 2
//1 3
//1 4
//2 4
//3 5
//4 5
//Enter the starting node: 0
