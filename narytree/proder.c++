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
vector<int>ans;
vector<int> preorder(Node* root)
{
      if (!root)
         return {};
      ans.emplace_back(root->data);
      for (auto i : root->child)
         preorder(i);

      return ans;
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

ans=preorder(root);

for(auto i:ans)
cout<<i<<" ";
   return 0;
}
