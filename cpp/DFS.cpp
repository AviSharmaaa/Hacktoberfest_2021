#include <iostream>
#include <vector>
using namespace std;

void DFSRec(vector<int> adj[], int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";
    for(auto x : adj[s])
        if(visited[x] == false)
            DFSRec(adj,x,visited);
}

void DFS(vector<int> adj[],int s, int v) {
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    DFSRec(adj,s,visited);
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
    /*int v = 7;
    vector<int> adj[7];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    printList(adj,v);*/

    int v = 6;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    printList(adj,v);
    cout << "\n\nDFS : ";
    DFS(adj,0,v);
    return 0;
}