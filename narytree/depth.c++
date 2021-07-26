#include <bits/stdc++.h>
using namespace std;
class Node
 {
 public:
   int data;
   vector<Node *>child;
   Node(int data)
   {
       this->data=data;
   }
};

int depthOfTree(Node *root){
   if (root==NULL)
      return 0;
   int maxDepth = 0;
   for(auto i: root->child)
      maxDepth = depthOfTree(i) + 1;
   
   return maxDepth;
}
int main()
{
Node *root = new Node(20);
(root->child).push_back(new Node(10));
(root->child).push_back(new Node(15));
(root->child[0]->child).push_back(new Node(1));
(root->child[0]->child).push_back(new Node(2));
(root->child[0]->child).push_back(new Node(3));
(root->child[1]->child).push_back(new Node(4));

   cout <<"The depth of the n-ary tree is "<< depthOfTree(root) << endl;
   return 0;
}
