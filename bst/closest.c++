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
void maxDiffUtil(Node *ptr, int k, int &min_diff,int &min_diff_key)
{
    if (ptr == NULL)
        return ;

    if (ptr->data == k)
    {
        min_diff_key = k;
        return;
    }

    if (min_diff > abs(ptr->data - k))
    {
        min_diff = abs(ptr->data - k);
        min_diff_key = ptr->data;
    }

    if (k < ptr->data)
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
    else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}

int maxDiff(Node *root, int k)
{
    int min_diff = INT_MAX, min_diff_key = -1;
    maxDiffUtil(root, k, min_diff, min_diff_key);
    return min_diff_key;
}

int main()
{
    Node *root = new Node(9);
    root->left    = new Node(4);
    root->right   = new Node(17);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right->right = new Node(22);
    root->right->right->left = new Node(20);
    int k = 18;
    cout << maxDiff(root, k);
    return 0;
}
