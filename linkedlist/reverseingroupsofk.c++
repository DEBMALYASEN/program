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
Node* reverse( Node* head,int k)
{
     Node* prev = NULL;
     Node* current = head;
     Node* next;
     int c=0;
    while (current &&c<k)
     {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        c++;
    }


    if(next)
    head->next=reverse(next,k);

    return prev;
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
    Node*t=reverse(head1,2);
    printList(t);

}
