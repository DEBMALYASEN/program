#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node *LevelOrder(Node *root , int data)
{
     if(root==NULL)
     {
        root = new Node(data);
        return root;
     }
     if(data <= root->data)
     root->left = LevelOrder(root->left, data);
     else
     root->right = LevelOrder(root->right, data);

     return root;
}

Node* constructBst(int arr[], int n)
{
    if(n==0)
    return NULL;

    Node *root =NULL;

    for(int i=0;i<n;i++)
    root = LevelOrder(root , arr[i]);

    return root;
}

void inorderTraversal(Node* root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};//level order
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = constructBst(arr, n);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}
