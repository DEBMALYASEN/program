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
Node* out=new Node(0);
Node* xx=out;
void interleave(Node*a,Node*b)
{

    while(a||b)
    {
        if(a)
        {
            out->next=a;
            out=out->next;
            a=a->next;
        }
        if(b)
        {
        out->next=b;
        out=out->next;
        b=b->next;
        }

    }
}


int main()
{
    int keys1[] = { 2 ,1 ,3,4};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
     Node* head1 = NULL;

    Node* head2 = NULL;
    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }

        int keys2[] = { 4,9};
        int n2 = sizeof(keys2) / sizeof(keys2[0]);


        for (int i = n2 - 1; i >= 0; i--)
        {
            push(&head2, keys2[i]);
        }

interleave(head1,head2);
printList(xx->next);
}
