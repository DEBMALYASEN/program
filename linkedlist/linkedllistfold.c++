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
Node* printMiddle( Node *head)
{
     Node *slow = head;
     Node *fast = head;

    if (head!=NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    return slow;
    }
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
Node* reverse( Node* head_ref,Node* x)
{
     Node* prev = NULL;
     Node* current = head_ref;
     Node* next;
    while (current!=x)
     {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;

    return head_ref;
}
Node* reverse1( Node* head_ref)
{
     Node* prev = NULL;
     Node* current = head_ref;
     Node* next;
    while (current)
     {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;

return head_ref;
}
void add(struct Node* X, struct Node* Y, struct Node **head)
{
    struct Node* prevNode = NULL;
    int carry = 0;

    while (X || Y)
    {

        int sum = 0;
        if (X)
            sum += X->data;

        if (Y)
            sum += Y->data;

        sum += carry;

        carry = sum / 10;
        sum = sum % 10;

         Node* node =new  Node(sum);

        if (*head == NULL)
        {
            prevNode = node;
            *head = node;
        }
        else
        {
            prevNode->next = node;
            prevNode = node;
        }
        if (X)
            X = X->next;


        if (Y)
            Y = Y->next;
    }

    if (carry != 0)
        push(&(prevNode->next), carry);

}
int main()
{
    int keys1[] = { 2 ,1 ,3,4};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
    struct Node* head1 = NULL;

   struct Node* out = NULL;
    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }
    printList(head1);
    Node* a=printMiddle(head1);
    printList(a);
    Node *b=reverse(head1,a);
    printList(b);

    a=reverse1(a);
    b=reverse1(b);


    add(a,b,&out);
    out=reverse1(out);

    printList(out);




}
