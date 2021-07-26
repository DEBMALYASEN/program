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


Node* mergeTrees(Node *root1, Node *root2, int m, int n)
{
    int arr1[n];
    int i = 0;
    storeInorder(root1, arr1, &i);

    int arr2[m];
    int j = 0;
    storeInorder(root2, arr2, &j);

    int *mergedArr = merge(arr1, arr2, m, n);

    return sortedArrayToBST (mergedArr, 0, m + n - 1);
}



void printInorder(node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";

    printInorder(node->right);
}


int *merge(int arr1[], int arr2[], int m, int n)
{

    int mergedArr[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }

    return mergedArr;
}


void storeInorder(node* node, int inorder[], int& index)
{
    if (node == NULL)
        return;
    storeInorder(node->left, inorder, index);
    inorder[index++] = node->data;
    storeInorder(node->right, inorder, index);
}




Node* sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    return NULL;

    int mid = (start + end)/2;

    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}


int main()
{

    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);


    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);

    Node *mergedTree = mergeTrees(root1, root2, 5, 3);


    printInorder(mergedTree);

    return 0;
}
