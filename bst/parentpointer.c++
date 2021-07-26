#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->parent=NULL;
    }
};


void inorder( Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
           cout<<root->data<<" ";
        if (root->parent == NULL)
          cout<<"Parent : NULL"<<endl;
        else
          cout<<"Parent  "<<root->parent->data<<endl;

        inorder(root->right);
    }
}

 Node* insert( Node* node, int key)
{

    if (node == NULL)
    return new Node(key);

    if (key < node->data)
    {
        Node *lchild = insert(node->left, key);
        node->left  = lchild;
        lchild->parent = node;
    }
    else if (key > node->data)
    {
        Node *rchild = insert(node->right, key);
        node->right  = rchild;
        rchild->parent = node;
    }

    return node;
}

int main()
{

    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    return 0;
}
