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

void inorderbuild(Node* root,vector<int>&a)
{
    if (root)
    {
        inorderbuild( root->left ,a);
        a.push_back( root->data );
        inorderbuild( root->right ,a);
    }
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
bool ispresent(vector<int>a,int K)
{
    set<int>s;
    s.insert(a[0]);
    for(int i=1;i<a.size();i++)
    {
        if(s.find(K-a[i])!=s.end())
        return true;
        else
        s.insert(a[i]);

    }
    return false;
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

    vector<int>a;
    inorderbuild(root,a);
    cout<<ispresent(a,13);


    return 0;
}
