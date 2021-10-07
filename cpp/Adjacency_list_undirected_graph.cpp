/*  Here we are Implementing the graph using the "Adjacency List" of the following graph.
 *
 *      0 ----- 1 ----- 3
 *      |       |
 *      --- 2 --- 
 *      
 *  The Time Complexity of Implementing the "Adjacency List" is O(v + E) 
 *  where V -> No. of vertices.
 *        E -> No. of Edges.
 */

#include <iostream>
#include <vector>
using namespace std;

void addElement(vector<int> adj[], int u, int v) {
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
    vector <int> adj[v];
    addElement(adj,0,1);
    addElement(adj,0,2);
    addElement(adj,1,2);
    addElement(adj,1,3);
    printList(adj,v);
    return 0;
}