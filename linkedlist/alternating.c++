
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int key, struct Node *ptr)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->next = ptr;

    return node;
}

void push(struct Node** head, int data)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }

    printf("null");
}

void swap(struct Node *first, struct Node *second)
{
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

void rearrange(struct Node *head)
{

    if (head == NULL)
        return;


    struct Node* prev = head;
    struct Node* curr = head->next;

    while (curr)
    {

        if (prev->data > curr->data)
            swap(prev, curr);



        if (curr->next && curr->next->data > curr->data)
            swap(curr->next, curr);

        prev = curr->next;

        if (!curr->next)
            break;
        

        curr = curr->next->next;
    }
}

int main(void)
{
    int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 6 };
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Node* head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        push(&head, keys[i]);
    }

    rearrange(head);
    printList(head);

    return 0;
}
