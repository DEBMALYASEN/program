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


int detectAndRemoveLoop( Node* list)
{
   Node *slow = list, *fast = list;

  while (slow && fast && fast->next)
  {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
          removeLoop(slow, list);

          return 1;
      }
  }

  return 0;
}


void removeLoop( Node* loop_node, Node* head)
{
  Node* ptr1 = loop_node;
  Node* ptr2 = loop_node;

  unsigned int k = 1, i;
  while (ptr1->next != ptr2)
  {
      ptr1 = ptr1->next;
      k++;
  }

  ptr1 = head;


  ptr2 = head;
  for (i = 0; i < k; i++)
      ptr2 = ptr2->next;

  while (ptr2 != ptr1)
   {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;//meeting
  }

  while (ptr2->next != ptr1)
      ptr2 = ptr2->next;

  ptr2->next = NULL;
}

int main()
{
    Node* head = new Node(50);
    head->next = head;
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);

    return 0;
}
