/**************

Reversing a Singly (forward) linked list using Recursion and Sliding Pointers.

**************/

#include <iostream>

class node{
    public:
        int data;
        node *next;
};

// SLIDING POINTER METHOD
void slideReverse(node* variable){
    node* p=variable;
    node* q=NULL;
    node* r=NULL;

    while(p!=NULL){
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }

    while(q!=NULL){
        std::cout << q->data << " ";
        q = q->next;
    }
}

// RECURSIVE METHOD
void recurReverse(node* variable){
    if(variable!=NULL){
        recurReverse(variable->next);
        std::cout << variable->data << " ";
    }
} 

int main (){

    int user;
    node *first = 0;
    node *temp = 0;
    std::cout << "Enter the elements of the linked list [Enter 0 to end insertion]:\n";
    std::cin >> user;
    while (user)
    {
        node *t = new node;
        t->data = user; // -> *(t).data
        t->next = NULL;
        if (first == NULL)
        {
            first = t;
            temp = t;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
            t = NULL;
        }
        std::cin >> user;
    }

    std::cout << "\n\n---Reversing the Linked List using Recursion---\n";
    recurReverse(first);

    std::cout << "\n\n---Reversing the Linked List using sliding pointers---\n";
    slideReverse(first);

    return 0;
}