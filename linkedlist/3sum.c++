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
Node* MergeSortdesc(Node* head1,Node* head2)
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
Node* MergeSort(Node* head1,Node* head2)
{
    Node* t=new Node(0);
    Node*head=t;
    while(head1 && head2)
    {
        if(head1->data <head2->data)// > descending order | < ascending order
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
Node* Sort1(Node* head)
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

     Node* first=Sort1(head);

     Node* second=Sort1(slow);

     Node* newhead=MergeSortdesc(first,second);

     return newhead;
}
int main()
{
    int keys1[] = { 12,28,6};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
    struct Node* head1 = NULL;

    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }
    int keys2[] = { 2,8,9,5,7,10};
    int n2 = sizeof(keys2) / sizeof(keys2[0]);
    struct Node* head2 = NULL;

    for (int i = n2 - 1; i >= 0; i--)
    {
        push(&head2, keys2[i]);
    }
    int keys3[] = { 11,12,10};
    int n3 = sizeof(keys3) / sizeof(keys3[0]);
    struct Node* head3 = NULL;

    for (int i = n3 - 1; i >= 0; i--)
    {
        push(&head3, keys3[i]);
    }
    Node *a=head1;
    Node *b=Sort(head2);
    Node *c=Sort1(head3);
    int k=279se;
    while(a)
    {   Node *bb=b;
        Node *cc=c;
        while(bb && cc)
        {
            int sum=a->data+bb->data+cc->data;
            if(sum==k)
            {
                cout<<" found";
                return 0;
            }
            else if(sum<k)
            {
                bb=bb->next;
            }
            else
            {
                cc=cc->next;
            }

        }
    }
    cout<<"not found";



}
