#include <iostream>
#include <vector>
#include <queue> // For using the queue in Kahn's algorithm

using namespace std;

vector<vector<int> > a;       // Adjacency matrix representing the graph
vector<int> indegre;         // Vector to store the in-degrees of the vertices
int n;                       // Number of nodes (vertices) in the graph

// Function to compute the in-degrees of each vertex
void find_indegre() {
    for (int j = 0; j < n; ++j) {
        indegre[j] = 0;      // Initialize in-degrees
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                indegre[j]++; // Increment in-degree of vertex j
            }
        }
    }
}

// Function to perform topological sorting using Kahn's algorithm
void topology() {
    vector<int> t;           // Vector to store the topological order
    queue<int> q;            // Queue to store vertices with in-degree 0

    find_indegre();         // Compute the in-degrees

    // Initialize the queue with vertices that have an in-degree of 0
    for (int i = 0; i < n; ++i) {
        if (indegre[i] == 0) {
            q.push(i);
        }
    }

    // Process the vertices
    while (!q.empty()) {
        int u = q.front();   // Get vertex with in-degree 0
        q.pop();            // Remove it from the queue
        t.push_back(u);     // Add it to the topological order
        
        for (int v = 0; v < n; ++v) {
            if (a[u][v] == 1) {   // For each adjacent vertex v of u
                indegre[v]--;     // Decrease the in-degree of v
                if (indegre[v] == 0) {
                    q.push(v);    // Push v onto the queue if its in-degree becomes 0
                }
            }
        }
    }

    // Print the topological order as alphabets
    cout << "The topological Sequence is:\n";
    for (int i = 0; i < t.size(); ++i) {
        char alphabet = 'A' + t[i];  // Convert index to corresponding alphabet
        cout << alphabet << " ";     // Output the topological order as alphabets
    }
    cout << endl;
}

int main() {
    cout << "Enter number of nodes: ";
    cin >> n;

    a.resize(n, vector<int>(n));  // Resize the adjacency matrix to n x n
    indegre.resize(n);            // Resize the in-degrees vector to size n

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];        // Read the adjacency matrix from user input
        }
    }
    
    topology();                    // Call the topological sorting function
    return 0;
}
