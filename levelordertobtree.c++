#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int  data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
class treenode
{
public:
    int data;
    treenode* right;
    treenode* left;
    treenode(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
Node *l=new Node(0);
Node *k=l;
int height(treenode* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}

void printCurrentLevel(treenode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        {
          Node* t=new Node(root->data);
            l->next=t;
            l=l->next;
        }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}
void level2btree(treenode *root)
{
    int h = height(root);
   int i;
   for (i = 1; i <= h; i++)
       printCurrentLevel(root, i);
}


void push(Node** head_ref, int new_data)
{

    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}



int main()
{
    treenode* root=new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);

    level2btree(root);
    printList(k->next);


}
