#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};


void push(Node** head_ref, int data)
{
    Node* node = new Node(data);
    node->next = (*head_ref);
    node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = node;

    (*head_ref) = node;
}


void insertAfter(Node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }

    Node* node = new Node(data);
    node->next = prev_node->next;
    prev_node->next = node;
    node->prev = prev_node;


    if (node->next != NULL)
        node->next->prev = node;
}


void append(Node** head_ref, int data)
{
    Node* node = new Node(data);

    Node* last = *head_ref;

    if (*head_ref == NULL)
    {
        node->prev = NULL;
        *head_ref = node;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = node;

    node->prev = last;

    return;
}

void sortedInsert( Node** head_ref, Node* Node)
{
    Node* current;

    if (*head_ref == NULL)
        *head_ref = Node;

    else if ((*head_ref)->data >= Node->data)
    {
        Node->next = *head_ref;
        Node->next->prev = Node;
        *head_ref = Node;
    }

    else
     {
        current = *head_ref;

        while (current->next != NULL &&current->next->data < Node->data)
            current = current->next;

        Node->next = current->next;

        if (current->next != NULL)
            Node->next->prev = Node;

        current->next = Node;
        Node->prev = current;
    }
}

void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }

    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->prev;
    }
}
void deleteNode(Node** head_ref, Node* del)
{

    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;



    free(del);
    return;
}


void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *current = *head_ref;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        //swap between cyerr->next and cu->pev
        current = current->prev;
    }

    if(temp != NULL )
        *head_ref = temp->prev;

}

void deleteNode(Node** head_ref, Node* del)
{
 if (*head_ref == NULL || del == NULL)
     return;

 if (*head_ref == del)
     *head_ref = del->next;

 if (del->next != NULL)
     del->next->prev = del->prev;


 if (del->prev != NULL)
     del->prev->next = del->next;

 free(del);
}


void deleteNodeAtGivenPos(Node** head_ref, int n)
{

 if (*head_ref == NULL || n <= 0)
     return;

  Node* current = *head_ref;
 int i;

 for (int i = 1; current != NULL && i < n; i++)
     current = current->next;

 if (current == NULL)
     return;

 deleteNode(head_ref, current);
}

int LargestInDLL(Node** head_ref)
{
  Node *max, *temp;
    temp = max = *head_ref;

    while (temp != NULL)
    {
        if (temp->data > max->data)
            max = temp;

        temp = temp->next;
    }
    return max->data;
}




bool isPalindrome( Node *left)
{
    if (left == NULL)
       return true;


    Node *right = left;
    while (right->next != NULL)
        right = right->next;

    while (left != right)
    {
        if (left->data != right->data)
            return false;

         left = left->next;
         right = right->prev;
    }
    return true;

}

int main()
{

    Node* head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    cout << "Created DLL is: ";
    printList(head);

    return 0;
}
