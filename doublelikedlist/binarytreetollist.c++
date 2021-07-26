#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;
    Node(int data)
    {
        this->left=NULL;
        this->right=NULL;
        this->data=data;
    }
};

Node *concatenate(Node *leftList, Node *rightList)
{

    if (leftList == NULL)
        return rightList;
    if (rightList == NULL)
        return leftList;

    Node *leftLast = leftList->left;

    Node *rightLast = rightList->left;

    leftLast->right = rightList;
    rightList->left = leftLast;

    leftList->left = rightLast;
    rightLast->right = leftList;

    return leftList;
}

Node *bTreeToCList(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *left = bTreeToCList(root->left);


    Node *right = bTreeToCList(root->right);

    root->left = root->right = root;

    return concatenate(concatenate(left, root), right);
}


void displayCList(Node *head)
{

    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);

    cout << "\n";
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head = bTreeToCList(root);
    displayCList(head);

    return 0;
}
