#include <iostream>
using namespace std;
const int MAX = 100; 
int adj[MAX][MAX]={0};   
int adjSize[MAX];    
bool visited[MAX];   
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < adjSize[node]; i++) {//C++ AUTOMATICALLY DOES NOT KNOW THE NUMBER OF NEIGHBOURERS FOR EACH NODE SO WE MAEK A ASJSIZE ARRAY TO DETECT ITS NEIGHBOURERS
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    for (int i = 0; i < nodes; i++) {
        adjsize[i] = 0;
        visited[i] = false;
    }
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][adjsize[u]++] = v; 
        adj[v][adjsize[v]++] = u;
    }
    cout << "DFS (start=0): ";
    dfs(0);
    return 0;
}

