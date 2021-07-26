#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data=data;
        this->next-NULL;
        this->prev=NULL;
    }
};

void push(Node** head_ref, Node* new_node)
{
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}


Node* revListInGroupOfGivenSize(Node* head, int k)
{
    Node *current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }


    return newHead;
}
int findSize( Node *node)
{
   int res = 0;
   while (node != NULL)
   {
       res++;
       node = node->next;
   }
   return res;
}
void rotate(Node** head_ref, int N)
{
    if (N == 0)
    return;

   Node* current = *head_ref;

    int count = 1;
    while (count < N && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    Node* NthNode = current;

    while (current->next != NULL)
        current = current->next;


    current->next = *head_ref;

    (*head_ref)->prev = current;

    *head_ref = NthNode->next;


    (*head_ref)->prev = NULL;

    NthNode->next = NULL;
}




void printList(Node* head)
{
    while (head != NULL)
     {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    push(&head, new Node(2));
    push(&head, new Node(4));
    push(&head, new Node(8));
    push(&head, new Node(10));

    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = revListInGroupOfGivenSize(head, k);
    cout << "\nModified list: ";
    printList(head);

    return 0;
}
