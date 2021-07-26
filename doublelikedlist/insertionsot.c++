#include <bits/stdc++.h>
using namespace std;

class Node
 {
public:
    int data;
    Node* prev, *next;
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};


void sortedInsert(Node** head_ref, Node* newNode)
{
     Node* current;

    if (*head_ref == NULL)
        *head_ref = newNode;

    else if ((*head_ref)->data >= newNode->data)
    {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else
    {
        current = *head_ref;

        while (current->next != NULL && current->next->data < newNode->data)
            current = current->next;


        newNode->next = current->next;

        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}

void insertionSort(Node** head_ref)
{
     Node* sorted = NULL;

     Node* current = *head_ref;

    while (current != NULL)
    {

        Node* next = current->next;

        current->prev = current->next = NULL;

        sortedInsert(&sorted, current);

        current = next;
    }

    *head_ref = sorted;
}

void printList( Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void push(Node** head_ref, int new_data)
{
     Node* new_node =new Node(new_data);

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

int main()
{
    Node* head = NULL;

    push(&head, 9);
    push(&head, 3);
    push(&head, 5);
    push(&head, 10);
    push(&head, 12);
    push(&head, 8);

    cout << "Doubly Linked List Before Sorting \n";
    printList(head);

    insertionSort(&head);

    cout << "nDoubly Linked List After Sorting ";
    printList(head);

    return 0;
}
