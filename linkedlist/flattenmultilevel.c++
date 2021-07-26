#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
     Node *next;
    Node *down;
    Node(int data)
    {
        this->data=data;
        this->next=this->down=NULL;
    }
};

Node* flattenList(Node* node)
{

    if (node == NULL)
        return NULL;

    static Node *last;
    last = node;

    Node *next = node->next;

    if (node->down)
       node->next = flattenList(node->down);

    if (next)
       last->next = flattenList(next);

    return node;
}
Node* flattenList2(Node* head)
{
    Node* headcop = head;
    stack<Node*> s;
    s.push(head);
    Node* prev = NULL;

    while (!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        if (temp->next)
            s.push(temp->next);
        if (temp->down)
            s.push(temp->down);

        if (prev != NULL)
            prev->next = temp;

        prev = temp;
    }
    return headcop;
}

void printFlattenNodes(Node* head)
{
    while (head)
    {
    cout<< head->data<<" ";
    head = head->next;
    }

}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->down = new Node(7);
    head->next->down->down = new Node(9);
    head->next->down->down->down = new Node(14);
    head->next->down->down->down->down = new Node(15);
    head->next->down->down->down->down->next= new Node(23);
    head->next->down->down->down->down->next->down = new Node(24);
    head->next->down->next = new Node(8);
    head->next->down->next->down = new Node(16);
    head->next->down->next->down->down = new Node(17);
    head->next->down->next->down->down->next = new Node(18);
    head->next->down->next->down->down->next->next= new Node(19);
    head->next->down->next->down->down->next->next->next= new Node(20);
    head->next->down->next->down->down->next->next->next->down = new Node(21);
    head->next->down->next->next = new Node(10);
    head->next->down->next->next->down = new Node(11);
    head->next->down->next->next->next = new Node(12);

    head = flattenList2(head);
    printFlattenNodes(head);
}
