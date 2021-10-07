/*  Here we have used Kahn's Algorihtm to detect cycle in directed Graph    */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool cycle_detection_using_kahns_algo(vector<int> adj[], int v) {
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++) {
        for(auto x : adj[i]) {
            indegree[x]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++)
        if(indegree[i] == 0)
            q.push(i);
    int count = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto x : adj[u]) {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }
        count++;
    }
    return (count!=v);
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

int main() {
    int v = 6;
    vector<int> adj[v];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,3,1);
    addEdge(adj,2,3);
    addEdge(adj,4,1);
    bool res = cycle_detection_using_kahns_algo(adj,v);
    if(res)     cout << "Cycle Detected\n";
    else        cout << "No Cycle Detected\n";
    return 0;
}