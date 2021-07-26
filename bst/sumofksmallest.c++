#include<bits/stdc++.h>
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

Node* insert(Node* root, int key)
{
    if (root == NULL)
    return new Node(key);
    if (root->key > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int ksmallestElementSumRec(Node *root, int k, int &count)
{

    if (root == NULL)
        return 0;
    if (count > k)
        return 0;

    int res = ksmallestElementSumRec(root->left, k, count);

    if (count >= k)
        return res;

    res += root->data;
    count++;

    if (count >= k)
      return res;

    // If count is less than k, return right subtree Nodes
    return res + ksmallestElementSumRec(root->right, k, count);
}

int ksmallestElementSum(Node *root, int k)
{
   int count = 0;
   ksmallestElementSumRec(root, k, count);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 22);

    int k = 3;
    cout <<  ksmallestElementSum(root, k) <<endl;
    return 0;
}
