#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->parent=NULL;
    }
};
Node* minValue(Node* node)
{
   Node* current = node;

   while (current->left != NULL)
       current = current->left;

   return current;
}
 Node* inOrderSuccessor(Node* root,Node* n)//inOrderSuccessor ofn
{

    if (n->right != NULL)
        return minValue(n->right);

     Node* p = n->parent;

    while (p != NULL && n == p->right)
    {
        n = p;
        p = p->parent;
    }
    return p;
}



Node* insert(Node* root, int key)
{
    if (root == NULL)
    return new Node(key);
    else
    {
        Node *temp;
            if (key <=root->data )
            {
                temp=insert(root->left, key);
                root->left =temp ;
                temp->parent=root;
            }
           else
           {
               temp=insert(root->right, key);
               root->right =temp ;
               temp->parent=root;
           }
    }

    return root;
}

int main()
{
     Node *root = NULL, *temp, *succ, *min;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;

    succ = inOrderSuccessor(root, temp);
    if (succ != NULL)
        printf(
            "\n Inorder Successor of %d is %d ",
            temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");

    return 0;
}
