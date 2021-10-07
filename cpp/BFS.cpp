#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[],int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[], int v) {
    for(int i=0;i<v;i++) {
        cout << i << " : ";
        for(int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}

void BFS(vector<int> adj[], int v, int s) {
    queue <int> q;
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    
    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int x : adj[u]) {
            if(visited[x] == false) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    int v = 5;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    printList(adj,v);

    cout << "\n\nBFS : ";
    BFS(adj,v,4);
    return 0;
}