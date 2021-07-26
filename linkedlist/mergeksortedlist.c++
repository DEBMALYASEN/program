#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << " —> ";
        node = node->next;
    }
    cout << "nullptr";
}




Node* mergeKLists(vector<Node*>&list)
 {
    Node* dummy = new Node(0);

    priority_queue<int,vector<int>,greater<int>>minheap;

    for(auto head : list)
    {
        while(head)
        {
            minheap.push(head->data);
            head=head->next;
        }
    }

    Node* tmp = dummy;
    while(!minheap.empty())
    {
        tmp->next = new Node(minheap.top());
        minheap.pop();
        tmp=tmp->next;
    }
    return dummy->next;

}

int main()
{
    vector<Node*>list;
    list[0] = new Node(1);
    list[0]->next = new Node(5);
    list[0]->next->next = new Node(7);

    list[1] = new Node(2);
    list[1]->next = new Node(3);
    list[1]->next->next = new Node(6);
    list[1]->next->next->next = new Node(9);

    list[2] = new Node(4);
    list[2]->next = new Node(8);
    list[2]->next->next = new Node(10);

    Node* head = mergeKLists(list);
    cout<<head->data;d
    printList(head);

    return 0;
}
