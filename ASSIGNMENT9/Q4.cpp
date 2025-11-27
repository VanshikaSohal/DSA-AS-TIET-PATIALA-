#include <iostream>
using namespace std;
#define INF 999999
int main() {
    int n;
    cin >> n;   
    int graph[100][100];   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int start;
    cin >> start;
    int dist[100];
    int visited[100];
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for(int count = 0; count < n - 1; count++) {
        int mindi = INF, u = -1;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < mindi) {
                mindi = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        for(int v = 0; v < n; v++) {
            if(graph[u][v] != 0 && !visited[v]) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << "Distance to node " << i << " is " << dist[i] << endl;
    }
    return 0;
}
