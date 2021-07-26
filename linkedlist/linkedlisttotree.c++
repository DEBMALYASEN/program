#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
class treeNode
{
public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
void inorder(struct treeNode*root)
{

    if(root!=nullptr)
    {
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}
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
treeNode* conversion(struct Node*root)
{
    if(!root)
    return nullptr;
    treeNode *roott=new treeNode(root->data);

    treeNode*curr=roott;

    root=root->next;
    while(root)
    {
        treeNode *t=new treeNode(root->data);
        if(root->data>curr->data)
        {
            curr->left=t;
            curr=curr->left;
        }
        else
        {
            curr->right=t;
            curr=curr->right;
        }

    root=root->next;
     }
     return roott;
 }
 int main(void)
 {
     int keys1[] = { 5, 2, 6, 7, 8, 1, 10, 12, 6 };
     int n1 = sizeof(keys1) / sizeof(keys1[0]);
     struct Node* head1 = NULL;

     for (int i = n1 - 1; i >= 0; i--)
     {
         push(&head1, keys1[i]);
     }


     printList(head1);

     struct treeNode*T=conversion(head1);
     inorder(T);
     return 0;
 }
