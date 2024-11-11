#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int vertices, int source, vector<vector<pii>> &adjList) {
    vector<int> dist(vertices, INT_MAX);  // Distance vector to store shortest path to each vertex
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap priority queue

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if the current distance is greater than already found shortest distance
        if (currentDist > dist[u]) continue;

        // Check each adjacent vertex v of u
        for (auto &[v, weight] : adjList[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Display the shortest distances
    cout << "Vertex \t Distance from Source (" << source << ")\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " \t " << dist[i] << '\n';
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<pii>> adjList(vertices);  // Adjacency list to store the graph

    cout << "Enter the edges in the format (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});  // Remove this line if graph is directed
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(vertices, source, adjList);

    return 0;
}
