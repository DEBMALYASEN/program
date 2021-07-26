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

int maxelpath(Node *q, int x)//max between node and ancestor(Q )
{
    Node *p = q;

    int mx = INT_MIN;


    while (p -> data != x)
    {
        if (p -> data > x)
        {
            mx = max(mx, p -> data);
            p = p -> left;
        }
        else
        {
            mx = max(mx, p -> data);
            p = p -> right;
        }
    }

    return max(mx, x);
}

int maximumElement( Node *root, int x, int y)
{
    Node *p = root;

    while ((x < p -> data && y < p -> data) || (x > p -> data && y > p -> data))
    {
        if (x < p -> data && y < p -> data)
            p = p -> left;

        else if (x > p -> data && y > p -> data)
            p = p -> right;
    }

    return max(maxelpath(p, x), maxelpath(p, y));
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


int main()
{
    int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
    int a = 1, b = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = NULL;

    for (int i = 0; i < n; i++)
        insert(root, arr[i]);

    cout << maximumElement(root, a, b) << endl;

    return 0;
}
