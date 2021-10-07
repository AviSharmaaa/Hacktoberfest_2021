/*  Topological Sorting using DFS
 *  Topological sorting is done on Directed Acyclic Graph (DAG). Time complexity of this algorithm is O(V+E)
 *  The algorithm is as follows : 
 *  1)  create an empty stack st
 *  2)  For every vertex u do the following 
 *      if u is not visited
 *      DFS(u,st)
 *  3)  while stack is not empty, print the stack top.
 *  -------------------------------------------------------------
 *  DFS(u,st)
 *  1)  mark u as visited.
 *  2)  for every adjacent v of u
 *      if v is not visited
 *          DFS(v,st)
 *  3)  push u in stack st.
 */ 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], int s, vector<bool> &visited, stack<int> &st) {
    visited[s] = true;
    for(auto x : adj[s]) {
        if(visited[x] == false) {
            DFS(adj,x,visited,st);
        }
    }
    st.push(s);
}

void Topological_Sort(vector<int> adj[],int v) {
    vector<bool> visited(v,false);
    stack <int> st;
    for(int i=0;i<v;i++) {
        if(visited[i] == false) 
            DFS(adj,i,visited,st);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

int main() {
    int v = 6;
    vector<int> adj[v];

    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,5);
    addEdge(adj,2,5);
    addEdge(adj,4,2);
    addEdge(adj,5,3);
    Topological_Sort(adj,v);
    return 0;
}