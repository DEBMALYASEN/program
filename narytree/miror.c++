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

void mirrorTree(Node * root)
{
   if (root == NULL)
      return;

   int n = root->child.size();
   if (n < 2)
      return;

   for (int i = 0; i < n; i++)
      mirrorTree(root->child[i]);

   reverse(root->child.begin(), root->child.end());
}
void printTree(Node * root)
{
   if (root == NULL)
      return;

   queue<Node *>q;
   q.push(root);

   int level = 0;

   while (!q.empty())
   {
      int n = q.size();
      ++level;
      cout << "Level " << level << ": ";
      while (n > 0)
      {
         Node * p = q.front();
         q.pop();
         cout << p->data << " ";
         for (int i=0; i<p->child.size(); i++)
            q.push(p->child[i]);

         n--;
      }
      cout << endl;
   }
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
   cout << "Tree traversal before mirroring\n";
   printTree(root);
   mirrorTree(root);
   cout << "\nTree traversal after mirroring\n";
   printTree(root);
   return 0;
}
