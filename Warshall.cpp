#include <iostream>
#include <vector>
using namespace std;

void transitiveClosure(vector<vector<int> >& graph) {
    int n = graph.size();
    vector<vector<int> > reach(n, vector<int>(n));
    
    // Initialize the reach matrix with the graph's adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            reach[i][j] = graph[i][j];
        }
    }
    
    // Warshall's algorithm to compute transitive closure
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    
    // Print the transitive closure
    cout << "Transitive Closure of the given graph:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    vector<vector<int> > graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (0s and 1s):" << endl;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    
    transitiveClosure(graph);
    return 0;
}

// Enter the number of vertices: 4
// Enter the adjacency matrix (0s and 1s):
// 0 1 0 0
// 0 0 1 0
// 1 0 0 1
// 0 0 0 0
