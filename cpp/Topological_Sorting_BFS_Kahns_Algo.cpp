/*  Kahn's Algorithm
 *  This algorithm is used for topological sorting of DAG(Directed Acyclic Graph) 
 *  Kahn's Algo uses BFS for it. The algorithm goes like :
 *  1)  Compute indegree of all vertex
 *  2)  Create and empty queue q
 *  3)  Push all those vertex with zero indegree.
 *  4)  while (queue is not empty) 
 *      a)  u = queue.pop()
 *      b)  print u
 *      c)  Reduce indegree of all adjacent of u by 1
 *      d)  if indegree of any vertex equls zero then push it in queue
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topological_sorting(vector<int> adj[], int v) {
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++)
        for(int x : adj[i])
            indegree[x] ++;

    queue<int> q;
    for(int i=0;i<v;i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto x : adj[u]) { 
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void printList(vector<int> adj[], int v) {
    for(int i=0;i<v;i++) {
        cout << i << " : ";
        for(int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    int v = 6;
    vector<int> adj[v];
    /*addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,1,5);
    addEdge(adj,3,4);*/
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,5);
    addEdge(adj,2,5);
    addEdge(adj,4,2);
    addEdge(adj,5,3);
    //printList(adj,v);
    topological_sorting(adj,v);
    return 0;
}