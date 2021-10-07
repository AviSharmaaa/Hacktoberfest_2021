#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* build_tree(){
    int d;
    cin >> d;
    if(d == -1)
        return NULL;
    Node *n = new Node(d);
    n->left = build_tree();
    n->right = build_tree();
    return n;
}

void print_level_order(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // For printing all the nodes at one level in one line

    while(!q.empty()){
        Node *temp = q.front();
        if(temp == NULL){
            cout << "\n";
            q.pop();
            if(!q.empty())
                q.push(NULL); // for a new level at rear end of the queue
        }
        else{
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            cout << temp->data << " ";
        }
    }
}

int main() {
    Node *root = build_tree();
    print_level_order(root);
}

