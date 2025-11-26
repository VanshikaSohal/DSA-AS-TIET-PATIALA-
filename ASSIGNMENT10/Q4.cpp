#include <iostream>
using namespace std;
const int MAX = 10;
int n;
int graph[MAX][MAX];
bool visited[MAX];
int dist[MAX];
int distmin() {
    int minval = INT_MAX, minindex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minval) {
            minval = dist[i];
            minindex = i;
        }
    }
    return minindex;
}
void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    for (int count = 0; count < n ; count++) {
        int u = distmin();
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distances from node " << start << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " : " << dist[i] << endl;
    }
}
int main() {
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter adjacency matrix:";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    int start;
    cout << "Enter starting node: ";
    cin >> start;
    dijkstra(start);
    return 0;
}
