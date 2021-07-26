#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
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



Node*a=new Node(0);
Node*b=a;

void inorder(struct treeNode*root)
{

    if(root!=nullptr)
    {
        inorder(root->left);
        {
            Node* t=new Node(root->data);
           if(a==nullptr)
           {
               a=t;
               t=a;
           }
          else
          {
              a->next=t;
              a=a->next;
          }
        }
        inorder(root->right);
    }
}
void push (Node** head_ref, int new_data)
{
    Node* new_node = new Node( new_data);
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
int main()
{
     treeNode* root=new treeNode(1);
     root->left = new treeNode(2);
     root->right = new treeNode(3);
     root->left->left = new treeNode(4);
     root->left->right = new treeNode(5);


     inorder(root);
     printList(b->next);
}
