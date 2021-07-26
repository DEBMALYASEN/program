#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int  data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
void push(Node** head_ref, int new_data)
{

    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
Node* e=new Node(-1);
Node* ee=e;
Node* o=new Node(-1);
Node* oo=o;
void segregrateevenodd( Node*head)
{
    Node* t=head;

    while(t)
    {
        if(t->data %2==1)
        {
            oo->next=new Node(t->data);
            oo=oo->next;
        }
        else
        {
            ee->next=new Node (t->data);
            ee=ee->next;
        }
       t=t->next;
    }
     oo->next=e->next;
    printList(o->nexts);
}
int main()
{
    int keys1[] = { 12,28,6,3,5,7,1,4};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
    struct Node* head1 = NULL;

    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }
    segregrateevenodd( head1);
}
