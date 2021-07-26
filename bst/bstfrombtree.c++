#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
     node* left;
    node* right;
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


void storeInorder( node* node, int inorder[], int& i)
{

    if (node == NULL)
        return;

    storeInorder(node->left, inorder, i);


    inorder[i++] = node->data;



    storeInorder(node->right, inorder, i);
}

int countNodes( node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}


void arrayToBST(int* arr, node* root, int& i)
{

    if (root == NULL)
        return;

    arrayToBST(arr, root->left, i);


    root->data = arr[i];
    i++;


    arrayToBST(arr, root->right, i);
}
void binaryTreeToBST( node* root)
{
    if (root == NULL)
        return;
    int n = countNodes(root);
    int arr[n];
    int i = 0;

    storeInorder(root, arr, i);

    sort(arr,arr+n);

    i = 0;

    arrayToBST(arr, root, i);

    delete[] arr;
}



void printInorder( node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout<<node->data<<"  ";
    printInorder(node->right);
}

int main()
{
    node* root = NULL;
    root = new node(10);
    root->left = new node(30);
    root->right = new node(15);
    root->left->left = new node(20);
    root->right->right = new node(5);

    binaryTreeToBST(root);

    printInorder(root);

    return 0;
}
