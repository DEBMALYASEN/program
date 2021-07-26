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
        this->left=nullptr;
        this->right=nullptr;

    }
};


void MorrispreorderTraversal(Node* root)//preorrder
{
    Node *current, *pre;

    if (root == NULL)
        return;

    current = root;

    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout<< current->data;
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;


            if (pre->right == NULL)
            {
                pre->right = current;
                cout<< current->data;
                current = current->left;
            }

            else
            {
                pre->right = NULL;

                current = current->right;
            }
         }
    }
}


int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    MorrispreorderTraversal(root);

    return 0;
}
