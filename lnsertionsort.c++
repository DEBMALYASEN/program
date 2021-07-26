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
void insertionsort(Node* head)
{
    Node* x=head->next;
    Node* prev=head;

    while(x)
    {
        if(prev->data<=x->data)
            prev=x;
        else //1 2 5 6   4
        {
            Node *i =head;
            Node*p;
            while(i && i!=x)
            {
                if(i->data>x->data)// p i   prev x   x and p
                {

                    x->next=i;
                    p->next=x;
                    Node *d=prev->next;
                    prev->next=prev->next->next;
                    free(d);
                }
                else
                    p=i;
            i=i->next;
            }

            }
            x=x->next;
        }
        printList(head);
}


int main()
{
    int keys1[] = { 2,5 ,1 ,3,4,6,7,0,9,10,5};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
     Node* head1 = NULL;

    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }
    insertionsort(head1);
}
