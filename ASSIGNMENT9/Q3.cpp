#include <iostream>
using namespace std;
const int MAX = 10;
int n;
int graph[MAX][MAX]; 
bool visited[MAX]; 
void prim() {
    for (int i = 0; i < n; i++)
	visited[i] = false;
    visited[0] = true; 
    int edgecount = 0;
    int mincost, u, v;
    cout << "Edges in MST:";
    while (edgecount < n - 1) {
        mincost = 9999;
        u = -1; v = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < mincost) {
                        mincost = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            cout << u << " - " << v << " : " << mincost << endl;
            visited[v] = true;
            edgecount++;
        }
    }
}
int parentfind(int p, int parent[]) {
    while (parent[p] != p)
    p = parent[p];
    return p;
}
void kruskal() {
    int parent[MAX];
    for (int i = 0; i < n; i++)
	parent[i] = i;
    int edges[MAX * MAX][3]; 
    int edgecount = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j]) {
                edges[edgecount][0] = i;
                edges[edgecount][1] = j;
                edges[edgecount][2] = graph[i][j];
                edgecount++;
            }
    for (int i = 0; i < edgecount - 1; i++) {
        for (int j = 0; j < edgecount - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int t0 = edges[j][0], t1 = edges[j][1], t2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = t0;
                edges[j + 1][1] = t1;
                edges[j + 1][2] = t2;
            }
        }
    }
    cout << "Edges in MST ";
    for (int i = 0; i < edgecount; i++) {
        int u = edges[i][0], v = edges[i][1];
        int pu = parentfind(u, parent);
        int pv = parentfind(v, parent);
        if (pu != pv) {
            cout << u << " - " << v << " : " << edges[i][2] << endl;
            parent[pu] = pv; 
        }
    }
}
int main() {
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter adjacency matrix ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    int choice;
    cout << "Choose algorithm: 1.Prim  2.Kruskal Enter choice: ";
    cin >> choice;
    if (choice == 1)
    prim();
    else if (choice == 2)
    kruskal();
    else
    cout << "Invalid choice";
    return 0;
}

