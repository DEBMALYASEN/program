#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
struct Node* newNode(int key, struct Node *ptr)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->next = ptr;

    return node;
}
void push (Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

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

struct Node* replace(struct Node* head1,struct Node* head2,int x ,int y)
{


    struct Node*curr1=head1;
    struct Node*g=head1;
    struct Node*h=head1;
    struct Node*o=head1;
    struct Node*curr2=head2;
    struct Node*t=head2;

    for( int i=0;i<=y;i++)
    curr1=curr1->next;



    while(t->next)
    t=t->next;

    t->next=curr1;



    for(int i=1;i<x;i++)
      g=g->next;

     g->next=nullptr;



    g->next=curr2;


        return h;
}








int main(void)
{
    int keys1[] = { 5, 2, 6, 7, 8, 1, 10, 12, 6 };
    int n1 = sizeof(keys1) / sizeof(keys1[0]);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;


    int keys2[] = { 10,90,100 };
    int n2 = sizeof(keys2) / sizeof(keys2[0]);

    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }


    for (int i = n2 - 1; i >= 0; i--)
    {
        push(&head2, keys2[i]);
    }
    printList(head1);
    printList(head2);
    int m,n;
    cin>>m>>n;
    struct Node*T=replace(head1,head2,m,n);
    printList(T);
    return 0;
}
