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
void convertBSTtoDLL(node* root, node** head, node** tail)
{

    if (root == NULL)
        return;


    if (root->left)
        convertBSTtoDLL(root->left, head, tail);

    root->left = *tail;

    if (*tail)
        (*tail)->right = root;
    else
        *head = root;


    *tail = root;

    if (root->right)
        convertBSTtoDLL(root->right, head, tail);
}

bool isPresentInDLL(node* head, node* tail, int sum)
{
    while (head != tail)
    {
        int curr = head->key + tail->key;
        if (curr == sum)
            return true;
        else if (curr > sum)
            tail = tail->left;
        else
            head = head->right;
    }
    return false;
}

bool isTripletPresent(node *root)
{

    if (root == NULL)
    return false;


    node* head = NULL;
    node* tail = NULL;

    convertBSTtoDLL(root, &head, &tail);

    while ((head->right != tail) && (head->key < 0))
    {
        if (isPresentInDLL(head->right, tail, -1*head->key))
            return true;
        else
            head = head->right;
    }

    return false;
}


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

    if (isTripletPresent(root))
        cout << "Present";
    else
        cout << "Not Present";
    return 0;
}
