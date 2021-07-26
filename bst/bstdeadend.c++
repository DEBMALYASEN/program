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


void storeNodes(Node * root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return ;

    all_nodes.insert(root->data);
    if (root->left==NULL && root->right==NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }

    storeNodes(root-> left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

bool isDeadEnd(Node *root)
{

    if (root == NULL)
        return false ;

    unordered_set<int> all_nodes, leaf_nodes;

    all_nodes.insert(0);

    storeNodes(root, all_nodes, leaf_nodes);

    for (auto i:leaf_nodes)
    {
        if (all_nodes.find(i+1) != all_nodes.end() &&all_nodes.find(i-1) != all_nodes.end())
            return true;
    }

    return false ;
}


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

int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
