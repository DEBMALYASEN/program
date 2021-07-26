#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data=data;
    }
};




Node* extractLeafList(Node *root, Node **head_ref)
{

if (root == NULL)
return NULL;

if (root->left == NULL && root->right == NULL)
{
    root->right = *head_ref;
    if (*head_ref != NULL)
    (*head_ref)->left = root;

    *head_ref = root;

    return NULL;
}
 
root->right = extractLeafList(root->right, head_ref);
root->left = extractLeafList(root->left, head_ref);

return root;
}


void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}


void printList(Node *head)
{
    while (head)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
}

int main()
{
    Node *head = NULL;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Inorder Trvaersal of given Tree is:\n";
    print(root);

    root = extractLeafList(root, &head);

    cout << "\nExtracted Double Linked list is:\n";
    printList(head);

    cout << "\nInorder traversal of modified tree is:\n";
    print(root);
    return 0;
}
