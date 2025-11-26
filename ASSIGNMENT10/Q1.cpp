#include <iostream>
using namespace std;
void bfs(int start, int adj[][10], int adjSize[], bool visited[], int n) {
    int queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;
    while (front != rear) {
        int node = queue[front++];
        cout << node << " ";
        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = true;
            }
        }
    }
}
int main() {
    int n = 6;
    int adj[10][10]={0}; 
   cout << "BFS traversal starting from node: ";
    int adjsize[10];   
    for (int i = 0; i < n; i++) 
	adjsize[i] = 0;
    adj[0][adjsize[0]++] = 1;
    adj[1][adjsize[1]++] = 0;
    adj[0][adjsize[0]++] = 2;
    adj[2][adjsize[2]++] = 0;
    adj[1][adjsize[1]++] = 3;
    adj[3][adjsize[3]++] = 1;
    adj[2][adjsize[2]++] = 4;
    adj[4][adjsize[4]++] = 2;
    adj[3][adjsize[3]++] = 5;
    adj[5][adjsize[5]++] = 3;
    bool visited[10] = {false}; 
    for (int i = 0; i < n; i++)
	visited[i] = false;
    cout << "BFS traversal starting from node:";
    cout<<endl;
    bfs(0, adj, adjsize, visited, n);
    return 0;
}

