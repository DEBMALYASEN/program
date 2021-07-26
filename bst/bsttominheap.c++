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

void inorderTraversal(Node *root, vector<int>& arr)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, arr);

    arr.push_back(root->data);

    inorderTraversal(root->right, arr);
}

void BSTToMinHeap(Node *root, vector<int> arr, int&i)
{
    if (root == NULL)
        return;

    root->data = arr[++i];

    BSTToMinHeap(root->left, arr, i);

    BSTToMinHeap(root->right, arr, i);
}

void convertToMinHeapUtil(Node *root)
{

    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTToMinHeap(root, arr, i);
}

void preorderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    preorderTraversal(root->left);

    preorderTraversal(root->right);
}


int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMinHeapUtil(root);




    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);

    return 0;
}
