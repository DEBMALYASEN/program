#include <bits/stdc++.h>
using namespace std;
class Linked
{
Node head;

class Node
{
public:
    int data;
    Node* next,*child;
    Node(int  data)
    {
        this->data=data;
        this->next=nullptr;
        this->child=nullptr;
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

Node *merge(Node *first, Node *second)
{
	if (first == NULL)
		return second;

	if (second == NULL)
		return first;

	Node *merged;

	if (first->data < second->data)
	{
		merged = first;
		merged->child = merge(first->child, second);
	}
	else
	{
		merged = second;
		merged->child = merge(first, second->child);
	}
	return merged;
}

Node *flattenLinkedList(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	head->next = flattenLinkedList(head->next);

	head = merge(head, head->next);

	return head;
}
int main()
{
    Linked L=new Linked();

       L->head = L.push(L->head, 30);
       L->head = L.push(L->head, 8);
       L->head = L.push(L->head, 7);

       L->head->right = L.push(L->head->right, 20);
       L->head->right = L.push(L->head->right, 10);
      
       L->head->right->right = L.push(L->head->right->right, 50);
       L->head->right->right = L.push(L->head->right->right, 22);
       L->head->right->right = L.push(L->head->right->right, 19);

       L->head->right->right->right = L.push(L->head->right->right->right, 45);
       L->head->right->right->right = L.push(L->head->right->right->right, 40);
       L->head->right->right->right = L.push(L->head->right->right->right, 35);
       L->head->right->right->right = L.push(L->head->right->right->right, 20);

       L->head = L.flatten(L->head);

       L.printList();


}
