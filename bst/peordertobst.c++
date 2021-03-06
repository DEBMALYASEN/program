#include <bits/stdc++.h>
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


node* constructTreeUtil(int pre[], int* preIndex, int key,int min, int max, int size)
{

    if (*preIndex >= size)
        return NULL;

    node* root = NULL;

    if (key > min && key < max)
     {
        root = new Node(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);

        if (*preIndex < size)
            root->right = constructTreeUtil(pre, preIndex,pre[*preIndex], key, max, size);
        }
    }

    return root;
}

node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}





void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
    node* root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
