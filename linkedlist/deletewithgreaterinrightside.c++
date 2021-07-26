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
void push( Node**headRef, int data)
{
   Node* node = new Node(data);
    node->next = *headRef;
    *headRef = node;
}

void printList( Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
        cout<< ptr->data<<" ";
        ptr = ptr->next;
    }


}

void reverse(struct Node** headRef)
{
    struct Node* prev = NULL;
    struct Node* current = *headRef;

    while (current)
    {
        struct Node* next = current->next;

        current->next = prev;
        prev = current;

        current = next;
    }

    *headRef = prev;
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

    reverse(&head1);


    Node*t=head1->next;
    Node*prev=head1;
    Node*f=prev;
    while(t)
    {
        if(t->data>prev->data)
        {
            prev->next=new Node(t->data);
            prev=prev->next;

        }
        t=t->next;
    }
    reverse(&f);
    printList(f);





}
