#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
void push (Node** head_ref, int new_data)
{
    Node* new_node = new Node( new_data);
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
void lastoccurence(Node* node,int v)
{
    Node* temp=node,*prev;
    while(temp->next!=nullptr )
    {
        if(temp->next->data==v)
        prev=temp;

        temp=temp->next;

    }
    Node*x=prev->next;
    prev->next=prev->next->next;
    free(x);

}
int  main()
{
    int keys1[] = { 5, 2, 6, 7, 8, 1, 6, 12, 7};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
    struct Node* head1 = NULL;

    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }
    lastoccurence(head1,6);
    printList(head1);

}
