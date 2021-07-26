#include<bits/stdc++.h>
using namespace std
class Node
{
    int v;
    Node* l;
    Node* r;
    Node(int v)
    {
        this->v=v;
        l=nullptr;
        r=nullptr;
    }
};
int dfs(Node* root, vector<int>& a, int k)
   {
       if(!root)
           return 0;
       int cnt=0;
       for(int i=0;i<a.size();i++)
       {
           if(root->v+a[i]==k)
               cnt++;
           a[i]+=root->v;
       }
       a.push_back(0);
       int x = dfs(root->l, a, k);
       int y = dfs(root->r, a, k);
       return x+y+cnt;
   }

   int pathSum(Node* root, int k)
    {
       if(!root)
           return 0;
       vector<int> a = {0};
       int ans = dfs(root, a, k);
       return ans;
   }
