#include <iostream>
#include <vector>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], int parent) {
    visited[s] = true;
    for(auto u : adj[s]) {
        if(visited[u] == false && DFSRec(adj,u,visited,s) == true)
            return true;
        else if(u != parent)
            return true;
    }
    return false;
}

bool DFS(vector<int> adj[], int v) {
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++) {
        if(visited[i] == false && DFSRec(adj,i,visited,-1) == true)
            return true;
    }
    return false;
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
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    printList(adj,v);*/

    /*addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,3,4);
    printList(adj,v);*/

    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,2,3);
    printList(adj,v);

    bool res = DFS(adj,v);
    if(res)
        cout << "Cycle Detected\n";
    else 
        cout << "No Cycle Detected\n";
    return 0;
}