#include <iostream>
#include <vector>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], bool recSt[]) {
    visited[s] = true;
    recSt[s] = true;
    for(auto u : adj[s]) {
        if(visited[u] == false && DFSRec(adj,u,visited,recSt) == true) {   
               return true;
        }
        else if(recSt[u] == true) {
            cout << u;
            return true;
        }
    }
    recSt[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int v) {
    bool visited[v], recSt[v];
    for(int i=0;i<v;i++) {
        visited[i] = false;
        recSt[i] = false;
    }
    for(int i=0;i<v;i++) {
        if(visited[i] == false && DFSRec(adj,i,visited,recSt) == true)
            return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void printList(vector<int> adj[], int v) {
    for(int i=0;i<v;i++) {
        cout << i << " : ";
        for(auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    int v = 6;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,3);
    //printList(adj,v);
    bool res = DFS(adj,v);
    if(res)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Detected\n";
    return 0;
}