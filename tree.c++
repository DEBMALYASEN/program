#include<bits/stdc++.h>
using namespace std;
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

void preorder(Node* root)
{
    if(root!=nullptr)
    {
        cout<<root->v<<" ";
        preorder(root->l);
        preorder(root->r);

    }
}
int height(Node*root)
{
    if (root ==nullptr)
    return 0;
    int l=height(root->l);
    int r=height(root->r);
    if(l>r)
    return l+1;
    else
    return r+1;
}
void levelorder(Node*root ,int level)
{
    if(root==nullptr)
    return ;
    if(level==1)
    cout<<root->v<<" ";
    else if(level>1)
    {
        levelorder(root->l,level-1);
        levelorder(root->r,level-1);
    }
}
void slevelorder( Node*root ,int level)
{
    if(root==nullptr)
    return ;
    if(level==1)
    cout<<root->v<<" ";
    else if(level>1)
    {
        if(level%2==1)
        {
        levelorder(root->l,level-1);
        levelorder(root->r,level-1);
        }
        else
        {
        levelorder(root->r,level-1);
        levelorder(root->l,level-1);
        }
    }
}
void lorder(Node*root)
{
    int h=height(root);
    for (int i = 1; i <=h; ++i)
    levelorder(root , i);
}
void slorder( Node*root)
{
    int h=height(root);
    for (int i=1;i<=h;i++)
    slevelorder(root,i);
}
void Rlevelorder(Node* root)
{
    int h = height(root);
    for (int i=h; i>=1; i--)
        levelorder(root, i);
}
void inorderN(Node*root,int n)
{
    static int count=0;
    if(root!=nullptr)
    {
        inorderN(root->l,n);
        count++;
        if(count==n)
        cout<<root->v;
        inorderN(root->r,n);
    }
}
int leftMostNode( Node* root)
{
    while (root != NULL && root->l != NULL)
        root = root->l;
    return root->v;
}
int rightMostNode( Node* root)
{
    while (root != NULL && root->r != NULL)
        root = root->r;
    return root->v;
}


void diagonalP(Node* root,int d, unordered_map <int,vector<int>>&D)
{
    if(root==nullptr)
    return;
    D[d].push_back(root->v);
    diagonalP(root->l,d+1,D);
    diagonalP(root->r,d,D);
}

void diagonal(Node* root)
{
  unordered_map<int,vector<int>> D;

    diagonalP(root,0,D);

    for(auto i:D)
    {
        for(auto j: i.second)
           cout<<j<<" ";
        cout<<endl;
    }
}
void printLTraversal(Node* root)
{

     if (root == nullptr)
           return;


    queue< Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
             Node* front = q.front();
            q.pop();

            cout << front->v;

            if (front->l)
                q.push(front->l);


            if (front->r)
                q.push(front->r);

        }

    }

}
void inorder( Node* root)
{
    if (root == NULL)
        return;

    inorder(root->l);
    cout<<(root->v);
    inorder(root->r);
}

void preorder( Node* root, queue<int> &keys)
{
   if (root == nullptr) {
       return;
   }
   keys.push(root->v);
   preorder(root->l, keys);
   preorder(root->r, keys);
}



void iterativeinOrder( Node *root)
{
 stack< Node *> s;
   Node *curr = root;

 while (curr != NULL || !s.empty())
 {
     while (curr !=  NULL)
     {
         s.push(curr);
         curr = curr->l;
     }
     curr = s.top();
     s.pop();

     cout << curr->v << " ";

     curr = curr->r;

 }
}

void iterativePreorder(struct Node* root)
{

    if (root == NULL)
        return;

    stack<struct Node*> s;
    s.push(root);

    while (!s.empty())
     {
        struct Node* curr = s.top();
        cout<<curr->v;

        s.pop();

        if (curr->r)
            s.push(curr->r);
        if (curr->l)
            s.push(curr->l);
    }
}
void postOrderIterative(struct Node* root)
{
    if (root == NULL)
        return;

    stack<struct Node *> s1, s2;

    s1.push(root);
    struct Node* node;

    while (!s1.empty())
    {

        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->l)
            s1.push(node->l);
        if (node->r)
            s1.push(node->r);
    }

    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->v << " ";
    }
}

struct Node* buildTree(int in[], int pre[], int inStrt,int inEnd, unordered_map<int, int>& m)
{
    static int c = 0;

    if (inStrt > inEnd)
        return NULL;


    int curr = pre[c++];

    struct Node* Node ;
    Node->v=curr;
    Node->l=nullptr;
    Node->r=nullptr;


    if (inStrt == inEnd)
        return Node;


    int inIndex = m[curr];//index in inorder

    Node->l = buildTree(in, pre, inStrt, inIndex - 1, m);
    Node->r = buildTree(in, pre, inIndex + 1, inEnd, m);

    return Node;
}

struct Node* buldTreeWrap(int in[], int pre[], int len)
{
    unordered_map<int, int> m;
    for (int i = 0; i < len; i++)
        m[in[i]] = i;

    return buildTree(in, pre, 0, len - 1, m);
}


int main()
{
  /* struct Node* root=new Node(1);
   root->l = new Node(2);
   root->r = new Node(3);
   root->l->l = new Node(4);
   root->l->r = new Node(5);
   //preorder(root);
  // Rlevelorder(root);
   //cout<<leftMostNode(root);
   //cout<<height(root);
   //inorderN(root,1);
   //diagonal(root);
   inOrder( root);
   cout<<endl;
  // Rlevelorder(root);
   //slorder(root);*/
   int  in[] = { 1,2,3,4,5,6};
   int  pre[] = { 2,3,5,6,4,1 };
   struct Node* root = buldTreeWrap(in, pre, 6);

   inorder(root);

}

void connectLeafNodes(Node* root, Node* &head, Node* &prev)
{
    // base case
    if (root == nullptr) {
        return;
    }

    // If the current node is a leaf node, connect it with the previous leaf node
    // using the right pointer. If the previous leaf node does not exist,
    // make the current node as head of the list
    if (isLeaf(root))
    {
        if (prev == nullptr) {
            head = root;
        }
        else {
            prev->right = root;
        }
        prev = root;
    }

    // recur for the left and right subtree
    connectLeafNodes(root->left, head, prev);
    connectLeafNodes(root->right, head, prev);
}

// Function to check if the leaf traversal of two given binary trees is the same
bool isLeafTraversalSame(Node* x, Node* y)
{
    // connect leaf nodes of the first binary tree into a linked list
    Node* first = nullptr;
    Node* prev = nullptr;
    connectLeafNodes(x, first, prev);

    // connect leaf nodes of the second binary tree into a linked list
    Node* second = nullptr;
    prev = nullptr;
    connectLeafNodes(y, second, prev);

    // compare both lists and break the loop on the first data mismatch
    while (first && second && first->key == second->key)
    {
        first = first->right;
        second = second->right;
    }

    // return true only if both lists are empty at this point;
    // if any of the lists are not empty, that means the tree
    // contains more leaf nodes, or the leaf nodes don't match
    return !first && !second;
}


void convert(Node* root)
{

    queue<int> keys;

    inorder(root, keys);

    preorder(root, keys);
}
void printLeaves(struct Node* root)
{
    if (root == nullptr)
        return;
    printLeaves(root->l);
    if (!(root->l) && !(root->r))
        cout<<root->v;
    printLeaves(root->r);
}

bool isFull(struct Node*)
{
    if(root==nullptr)
    return true;
    if(root->l==nullptr && root->r==nullptr)
    return true;
    if(root->l && root->r)
    return(isFull(root->l)&& isFull(root->r));
    return false;
}
int areMirror(struct Node* a, struct Node* b)
{
    if (a==nullptr && b==nullptr)
        return true;


    if (a== nullptr|| b ==nullptr )
        return false;
    return a-> v == b->v &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}
int areIdentical(struct Node* a, struct Node* b)
{
    if (a==nullptr && b==nullptr)
        return true;


    if (a== nullptr|| b ==nullptr )
        return false;
    return  a->v == b->v &&areIdentical(a->l, b->l) &&
            areIdentical(a->r, b->r);
}
bool checkDupUtil( Node* root, unordered_set<int> &s)
{

    if (root == nullptr)
       return false;

    if (s.find(root->v) != s.end())
       return true;

    s.insert(root->v);

    return checkDupUtil(root->l, s) || checkDupUtil(root->r, s);
}
bool checkDup(struct Node* root)
{
    unordered_set<int> s;
    return checkDupUtil(root, s);
}
int countSubtreesWithSumX(Node* root,int& count, int x)
{
    if (!root)
        return 0;

    int count = 0;

    int l = countSubtreesWithSumX(root->l, count, x);

    int r= countSubtreesWithSumX(root->r, count, x);
    int sum=(l + r + root->v);
    if ( sum== x)
        count++;

    return sum;
}


int maxLevelSum( Node* root)
{

    if (root == NULL)
        return 0;

    int result = root->v;

    queue<struct Node*> q;
    q.push(root);

    while (!q.empty())
    {

        int count = q.size();

        int sum = 0;
        while (count--)
        {

            struct Node* temp = q.front();
            q.pop();


            sum = sum + temp->v;

            if (temp->l != NULL)
                q.push(temp->l);
            if (temp->r != NULL)
                q.push(temp->r);
        }

        result = max(sum, result);
    }

    return result;
}

unsigned int countNodes( Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->l)
            + countNodes(root->r));
}
bool isComplete (struct Node* root,
                     unsigned int index,
                     unsigned int number_nodes)
{

    if (root == nullptr)
        return (true);

    if (index >= number_nodes)
        return (false)

    return (isCompleteUtil(root->l, 2*index + 1,
                           number_nodes) &&
            isCompleteUtil(root->r, 2*index + 2,
                           number_nodes));
}


void getVerticalOrder( Node* root, int h, map<int, vector<int>> &m)
{

    if (root == nullptr)
        return;

    m[h].push_back(root->v);

    getVerticalOrder(root->l, h-1, m);

    getVerticalOrder(root->r, h+1, m);
}


void printVerticalOrder( Node* root)
{
    map < int ,vector<int> > m;
    int h = 0;
    getVerticalOrder(root, h,m);


    for(auto i:m)
    {
        for(auto j: i.second)
           cout<<j<<" ";
        cout<<endl;
    }
}

Node* sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    return nullptr;

    int mid = (start + end)/2;
    struct Node *root = newNode(arr[mid]);

    root->l= sortedArrayToBST(arr, start,mid - 1);

    root->r= sortedArrayToBST(arr, mid + 1, end);

    return root;

}


void rightLeafSum(Node *root, int *sum)
{
    if(!root)
        return;

    if(root->right)
        if(!root->right->left  && !root->right->right)
            sum += root->right->data;

    rightLeafSum(root->left, sum);
    rightLeafSum(root->right, sum);
}
void leftLeafSum(Node *root, int *sum)
{
    if(!root)
        return;

    if(root->left)
        if(!root->left->left  &&
                     !root-left->right)
            sum += root->left->data;

    leftLeafSum(root->left, sum);
    leftLeafSum(root->right, sum);
}
void sumOfParentOfX(Node* root, int& sum, int x)
{

    if (!root)
        return;
    if ((root->left && root->left->data == x) ||
        (root->right && root->right->data == x))
        sum += root->data;

    sumOfParentOfX(root->left, sum, x);
    sumOfParentOfX(root->right, sum, x);

}
int getTotalHeight(Node* root)
{
    if (root == NULL)
        return 0;

    return getTotalHeight(root->left) +
           getHeight(root) +
           getTotalHeight(root->right);
}
int findLargestSubtreeSumUtil(Node* root, int& ans)
{

    if (root == NULL)
        return 0;
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);

    ans = max(ans, currSum);
    return currSum;
}

int findLargestSubtreeSum(Node* root)
{

    if (root == NULL)
        return 0;
    int ans = INT_MIN;
    findLargestSubtreeSumUtil(root, ans);

    return ans;
}






void printBottom(Node* node, int dist, int level, auto &map)
{

    if (node == nullptr)
        return;

    if (level >= map[dist].second)
        map[dist] = { node->key, level };


    printBottom(node->left, dist - 1, level + 1, map);


    printBottom(node->right, dist + 1, level + 1, map);
}


void printBottom(Node* root)
{

//<horizontal dis->node,level
  map<int, pair<int, int>> map;

  printBottom(root, 0, 0, map);

  for (auto it: map)
      cout << it.second.first << " ";

}

int getDiameter(Node* root, int &diameter)
{

    if (root == nullptr)
        return 0;


    int left_height = getDiameter(root->left, diameter);
    int right_height = getDiameter(root->right, diameter);


    int diameter =max(diameter, left_height + right_height + 1);

    return max(left_height, right_height) + 1;
}


int getDiameter(Node* root)
{
    int diameter = 0;
    getDiameter(root, diameter);

    return diameter;
}



int findMinDepth(Node* root)
{

    if (root == nullptr)

        return 0;

    int l = findMinDepth(root->left);


    int r = findMinDepth(root->right);

    if (root->left == nullptr) {
        return 1 + r;
    }


    if (root->right == nullptr) {
        return 1 + l;
    }

    return min(l, r) + 1;
}



void printLeftBoundary(Node* root)
{
    Node* node = root;


    while (!(node->left==nullptr && node->right==nullptr))
    {
        cout << node->data << ' ';

        node = (node->left) ? node->left: node->right;
    }
}
void printRightBoundary(Node* root)
{

    if (!root || (node->left==nullptr && node->right==nullptr))
        return;
    printRightBoundary(root->right ? root->right: root->left);

    cout << root->data << ' ';
}
void printLeafNodes(Node* root)
{

    if (root == nullptr)
        return;


    printLeafNodes(root->left);


    if (node->left==nullptr && node->right==nullptr)
    {
        cout << root->data << ' ';
    }

    printLeafNodes(root->right);
}









void performBoundaryTraversal(Node* root)
{

    if (root == nullptr)
        return;



    cout << root->data << ' ';

    printLeftBoundary(root->left);


    printLeafNodes(root);





    printRightBoundary(root->right);
}

void printTop(Node* root, int dist, int level, auto &map)
{

    if (root == nullptr)
        return;


    if (map.find(dist) == map.end() || level < map[dist].second)
    {
        map[dist] = { root->key, level };
    }

    printTop(root->left, dist - 1, level + 1, map);

    printTop(root->right, dist + 1, level + 1, map);
}


void printTop(Node* root)
{

    map<int, pair<int, int>> map;

    printTop(root, 0, 0, map);

    for (auto it: map)
        cout << it.second.first << " ";

}
Node* insert(Node* root, int key)
{
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    }

    else {
        root->right = insert(root->right, key);
    }


    return root;
}


int findMaxDifference(Node* root, int &diff)//between node and descendants
{
    if (root == nullptr) {
        return INT_MAX;
    }

    int left = findMaxDifference(root->left, diff);
    int right = findMaxDifference(root->right, diff);

    int d = root->data - min(left, right);

    diff = max(diff, d);

    return min(min(left, right), root->data);
}

int findMaxDifference(Node* root)
{
    int diff = INT_MIN;
    findMaxDifference(root, diff);

    return diff;
}

void preorder(Node* root, int level, auto &map)
{

    if (root == nullptr) {
        return;
    }
    map[level]++;


    preorder(root->left, level + 1, map);
    preorder(root->right, level + 1, map);
}

void findMaxWidth(Node* root)
{
    unordered_map<int, int> map;

    preorder(root, 1, map);

    int result = 0;

    for (auto it: map) {
        result = max(result, it.second);
    }

    cout << "The Maximum width is " << result;
}


void leafNodeDistance(Node* node, vector<Node*> path,
                    unordered_set<Node*> &set, int dist)
{

    if (node == nullptr)
        return;



    if (node->left==nullptr && node->right==nullptr && path.size() >= dist)
    {
        set.insert(path[(path.size() - dist)]); //fial answer
        return;
    }

    path.push_back(node);


    leafNodeDistance(node->left, path, set, dist);
    leafNodeDistance(node->right, path, set, dist);
}



void leafNodeDistance(Node* node, int dist)//dis from root
{
    vector<Node*> path;

    unordered_set<Node*> set;

    leafNodeDistance(node, path, set, dist);

    for (Node* node: set)
     {
        cout << node->data << " ";
    }
}


int isHeightBalanced(Node* root, bool &isBalanced)
{
    if (root == nullptr || !isBalanced) {
        return 0;
    }

    int left_height = isHeightBalanced(root->left, isBalanced);

    int right_height = isHeightBalanced(root->right, isBalanced);

    if (abs(left_height - right_height) > 1)
     {
        isBalanced = false;
    }

    return max(left_height, right_height) + 1;
}

bool isHeightBalanced(Node* root)
{
    bool isBalanced = true;
    isHeightBalanced(root, isBalanced);

    return isBalanced;
}
void printRootToleafPaths(Node* node, vector<int> &path)
{

   if (node == nullptr) {
       return;
   }

   path.push_back(node->data);

   if (node->left==nullptr  and node->right==nullptr)
   {
       for (int data: path) {
           cout << data << " ";
       }
       cout << endl;
   }

   printRootToleafPaths(node->left, path);
   printRootToleafPaths(node->right, path);

   path.pop_back();
}

void printRootToleafPaths(Node* node)
{

   vector<int> path;

   printRootToleafPaths(node, path);
}
bool printAncestors(Node* root, int node)
{

    if (root == nullptr)
        return false;


    if (root->data == node)

        return true;


    bool left = printAncestors(root->left, node);

    bool right = false;
    if (!left) {
        right = printAncestors(root->right, node);
    }

    if (left || right) {
        cout << root->data << " ";
    }

    return left || right;
}
bool isNodePresent(Node* root, Node* node)
{

    if (root == nullptr)
        return false;


    if (root == node)
        return true;



    return isNodePresent(root->left, node) ||isNodePresent(root->right, node);
}

int findLevel(Node* root, Node* node, int level)
{

    if (root == nullptr)
        return INT_MIN;

 ]
    if (root == node)
        return level;



    int left = findLevel(root->left, node, level + 1);

    if (left != INT_MIN) {
        return left;
    }

    return findLevel(root->right, node, level + 1);
}



Node* findLCA(Node* root, Node* x, Node* y)
{

    if (root == nullptr) {
        return nullptr;
    }


    if (root == x || root == y) {
        return root;
    }
    Node* left = findLCA(root->left, x, y);

    Node* right = findLCA(root->right, x, y);


    if (left && right) {
        return root;
    }


    if (left) {
        return left;
    }

    if (right) {
        return right;
    }
}
int findDistance(Node* root, Node* x, Node* y)
{
    Node* lca = nullptr;

    if (isNodePresent(root, y) && isNodePresent(root, x)) {
        lca = findLCA(root, x, y);
    }
    else {
        return INT_MIN;
    }

            return findLevel(root, x, 0) + findLevel(root, y, 0) -
                    2*findLevel(root, lca, 0);

}


void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}










void invertBinaryTree(Node* root)
{
    if (root == nullptr)
        return;


    swap(root->left, root->right);

    invertBinaryTree(root->left);

    invertBinaryTree(root->right);
}

double process(string op, double x, double y)
{
    if (op == "+") { return x + y; }
    if (op == "-") { return x - y; }
    if (op == "×") { return x * y; }
    if (op == "/") { return x / y; }

    return 0;
}
double evaluate(Node* root)
{

    if (root == nullptr) {
        return 0;
    }

    if (root->left==nullptr && root->right==nullptr) {
        return stod(root->val);
    }

    double x = evaluate(root->left);
    double y = evaluate(root->right);

    return process(root->val, x, y);
}

int findMISSize(Node* root)
{
    if (root == nullptr) {
        return 0;
    }


    int excl = findMISSize(root->left) + findMISSize(root->right);


    int incl = 1;

    if (root->left) {
        incl += findMISSize(root->left->left) + findMISSize(root->left->right);
    }

    if (root->right) {
        incl += findMISSize(root->right->left) + findMISSize(root->right->right);
    }

    return max(excl, incl);
}


Node* truncate(Node* root)
{
    if (root == nullptr) {
        return nullptr;
    }
    root->left = truncate(root->left);
    root->right = truncate(root->right);

    if ((root->left && root->right) || isLeaf(root)) {
        return root;
    }


    Node* child = (root->left) ? root->left: root->right;
    delete root;
    return ch
}
void convert(int keys[], int low, int high, Node* &root)
{

    if (low > high) {
        return;
    }

    int mid = (low + high) / 2;

    root = newNode(keys[mid]);

    convert(keys, low, mid - 1, root->left);

    convert(keys, mid + 1, high, root->right);
}


Node* convert(int keys[], int n)
{

    sort(keys, keys + n);

    Node* root = nullptr;
    convert(keys, 0, n - 1, root);

    return root;
}
void flatten(struct Node* root)
{
    // base condition- return if root is NULL
    // or if it is a leaf node
    if (root == NULL || root->left == NULL &&
                        root->right == NULL) {
        return;
    }

    // if root->left exists then we have
    // to make it root->right
    if (root->left != NULL) {

        // move left recursively
        flatten(root->left);

        // store the node root->right
        struct Node* tmpRight = root->right;
        root->right = root->left;
        root->left = NULL;

        // find the position to insert
        // the stored value
        struct Node* t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }

        // insert the stored value
        t->right = tmpRight;
    }

    // now call the same function
    // for root->right
    flatten(root->right);
}
*/
