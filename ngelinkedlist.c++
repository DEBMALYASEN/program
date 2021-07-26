#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
struct Node* newNode(int key, struct Node *ptr)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->next = ptr;

    return node;
}
void push (Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;

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
vector<int> nextLargerNodes(Node* head)
{
        stack<pair<int,int>>s; //val index
        int size=0;
        Node* temp = head;
        while(temp)
        {
            size++;
            temp=temp->next;
        }
        vector<int> res(size);
        int i = 0;
        while(head)
        {
            while(!s.empty()&& s.top().first<head->data)
            {
                res[s.top().second]=head->data;
                s.pop();
            }
            s.push({head->data,i});
            head=head->next;
            i++;
        }
        return res;
    }

    int main(void)
    {
        int keys[] = { 5, 2, 6, 7, 8, 1, 10, 12, 6 };
        int n = sizeof(keys) / sizeof(keys[0]);

        struct Node* head = NULL;
        for (int i = n - 1; i >= 0; i--)
        {
            push(&head, keys[i]);
        }

        vector<int>t=nextLargerNodes(head);
        for(auto i :t)
        cout<<i<<" ";

        return 0;
    }
