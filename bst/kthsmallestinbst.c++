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
Node* insert(Node* node, int data)
{

    if (node == NULL)
        return node = new Node(data);

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }

    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}
int KSmallestUsingMorris(Node *root, int k)
{
    int count = 0;

    int ksmall = INT_MIN;
    Node *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            count++;
            if (count==k)
                ksmall = curr->data;

            curr = curr->right;
        }
        else
        {
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;

            if (pre->right==NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }


            else
            {

                pre->right = NULL;

                count++;

                if (count==k)
                    ksmall = curr->data;

                curr = curr->right;
            }
        }
    }
    return ksmall;
}

int main()
{

    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    for (int k=1; k<=7; k++)
       cout << KSmallestUsingMorris(root, k) << " ";

    return 0;
}
