#include <iostream>
#include <vector>
using namespace std;

void DFSRec(vector<int> adj[], int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";
    for(auto x : adj[s]) 
        if(visited[x] == false) 
            DFSRec(adj,x, visited);
}

void DFS(vector<int> adj[], int v) {
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++) {
        if(visited[i] == false)
            DFSRec(adj,i,visited);
    }
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[], int v) {
    for(int i=0;i<v;i++) {
        cout << i << " : ";
        for(auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    int v = 4;
    vector<int> adj[v];
    /*addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,3,4);
    printList(adj,v);*/

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    DFS(adj,v);
    return 0;
}