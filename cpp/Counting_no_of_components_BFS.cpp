#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int v, int s, bool visited[]) {
    queue <int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto x : adj[u]) {
            if(visited[x] == false) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int BFSD(vector<int> adj[], int v) {
    bool visited[v];
    for(int i=0;i<v;i++) 
        visited[i] = false;
    int count  = 0;
    for(int i=0;i<v;i++) {
        if(visited[i] == false) {
            BFS(adj,v,i,visited);
            count ++;
        }
    }
    return count;
}

void addEdge(vector<int> adj[], int u, int v) {
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
    cout << endl;
}

int main() {
    int v = 9;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,3,4);
    addEdge(adj,5,6);
    addEdge(adj,5,7);
    addEdge(adj,7,8);
    printList(adj,v);
    cout << "BFS : ";
    int components = BFSD(adj,v);
    cout << "\nComponents in Graph : " << components << endl;
    return 0;
}