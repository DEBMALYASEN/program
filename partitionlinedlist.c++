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
Node* out1=new Node(0);
Node* out2=new Node(0);


Node* xx=out;
Node*yy=out1;
Node*zz=out2;
void partition(Node* a,int k)
{
    while(a)
    {
        if(a->data<k)
        {
            out->next=new Node(a->data);
            out=out->next;
            a=a->next;
        }
        else if(a->data==k)
        {
            out1->next=new Node(a->data);
            out1=out1->next;
            a=a->next;
        }
        else
        {
            out2->next=new Node(a->data);
            out2=out2->next;
            a=a->next;
        }
    }
    out->next=yy->next;
    out1->next=zz->next;
    printList(xx->next);

}
int main()
{
    int keys1[] = { 2,5 ,1 ,3,4,6,7,0,9,10,5};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
     Node* head1 = NULL;

    Node* head2 = NULL;
    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }
    partition(head1,5);
}
