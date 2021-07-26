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

bool inRange(Node* root, int low, int high)
{
    return root->data >= low && root->data <= high;
}

bool getCountUtil(Node* root, int low, int high, int& count)
{

    if (root == NULL)
        return true;

    bool l = getCountUtil(root->left, low, high, count);
    bool r = getCountUtil(root->right, low, high, count);


    if (l && r && inRange(root, low, high))
    {
        ++count;
        return true;
    }

    return false;
}


int getCount(Node* root, int low, int high)
{
    int count = 0;
    getCountUtil(root, low, high, count);
    return count;
}

int main()
{

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;
    cout << "Count of subtrees in [" << l << ", "<< h << "] is " << getCount(root, l, h);
    return 0;
}
