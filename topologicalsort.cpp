#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
vector<vector<int> > a;      
vector<int> indegre;       
int n;                     
void find_indegre() {
    for (int j = 0; j < n; ++j) {
        indegre[j] = 0;      
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                indegre[j]++; 
            }
        }
    }
}
void topology() {
    vector<int> t;           
    queue<int> q;            

    find_indegre();       

    for (int i = 0; i < n; ++i) {
        if (indegre[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();   
        q.pop();            
        t.push_back(u);   
        
        for (int v = 0; v < n; ++v) {
            if (a[u][v] == 1) {   
                indegre[v]--;  
                if (indegre[v] == 0) {
                    q.push(v);    
                }
            }
        }
    }
    cout << "The topological Sequence is:\n";
    for (int i = 0; i < t.size(); ++i) {
        char alphabet = 'A' + t[i];  
        cout << alphabet << " ";    
    }
    cout << endl;
}
int main() {
    cout << "Enter number of nodes: ";
    cin >> n;

    a.resize(n, vector<int>(n));  
    indegre.resize(n);            

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];      
        }
    }
    topology();                
    return 0;
}



//Enter number of nodes: 6
//Enter the adjacency matrix:
//0 1 0 0 0 0
//0 0 1 0 0 0
//0 0 0 1 0 0
//0 0 0 0 1 0
//0 0 0 0 0 1
//1 0 0 0 0 0
