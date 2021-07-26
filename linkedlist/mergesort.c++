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
Node* MergeSort(Node* head1,Node* head2)
{
    Node* t=new Node(0);
    Node*head=t;
    while(head1 && head2)
    {
        if(head1->data > head2->data)// > descending order | < ascending order
        {
            t->next=head1;
            head1=head1->next;
            t=t->next;
        }
        else
        {
            t->next=head2;
            head2=head2->next;
            t=t->next;
        }
    }
    if(!head1)
    t->next=head2;
    if(!head2)
    t->next=head1;
    return head->next;
}
Node* Sort(Node* head)
{
     if(!head || !head->next)
     return head;
     Node* slow=head,*temp=head,*fast=head;

     while(fast && fast->next)
     {
         temp=slow;
         slow=slow->next;
         fast=fast->next->next;
     }
     temp->next=NULL;

     Node* first=Sort(head);

     Node* second=Sort(slow);

     Node* newhead=MergeSort(first,second);

     return newhead;
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
    Node*p=Sort(head1);
    printList(p);

}
