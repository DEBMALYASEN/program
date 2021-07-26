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

Node* removeOutsideRange(Node *root, int min, int max)
{

   if (root == NULL)
      return NULL;

   root->left =  removeOutsideRange(root->left, min, max);
   root->right =  removeOutsideRange(root->right, min, max);



   if (root->data < min)
   {
       Node *rChild = root->right;
       delete root;
       return rChild;
   }

   if (root->data > max)
   {
       Node *lChild = root->left;
       delete root;
       return lChild;
   }


   return root;
}



Node* insert(Node* root, int key)
{
    if (root == NULL)
       return new Node(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}

void inorderTraversal(Node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);

    root = removeOutsideRange(root, -10, 13);

    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);

    return 0;
}
