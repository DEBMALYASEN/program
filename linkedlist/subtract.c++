#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int  data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
void push(Node** head_ref, int new_data)
{

    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
Node* paddingzero(Node* a ,int k)
{

   if(k<=0)
   return a;

    Node* p=new Node(-1);
    Node* q=p;

    while(k--)
    {
      p->next=new Node(0);
      p=p->next;
    }
    p->next=a;
    return q->next;
}
int getLength(Node* Node)
{
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}
vector<int> numbertoaray(int n)
{
    int d;
    vector<int>x;
    while(n)
    {
        d=n%10;
        x.push_back(d);
        n/=10;

    }
    reverse(begin(x),end(x));
    return x;

}

void subtract (Node *a,Node *b)
{
    int n1=getLength(a);
    int n2=getLength(b);
    Node *e=a;
    Node *r=b;
    int x=0,y=0;
    for(int i=n1-1;i>=0;i--)
    {
        x+=e->data*pow(10,i);
        e=e->next ;
    }


    for(int i=n2-1;i>=0;i--)
    {
        y+=r->data*pow(10,i);
        r=r->next ;
    }

    Node* out = NULL;
    int ans =x-y;
    int gans=abs(x-y);

     if(ans>=0)
    {

        vector<int>t=numbertoaray(gans);

        for (int i = t.size() - 1; i >= 0; i--)
            push(&out, t[i]);


    }
    if(ans<0)
    {
        vector<int>t=numbertoaray(gans);

        for (int i = t.size() - 1; i >= 0; i--)
            push(&out, t[i]);

    }
    if(ans>=0)
    printList(out);
    else
    {
        cout<<"-";
        printList(out);
    }

}









int main()
{
    int keys1[] = {1,5,6,7,8,9,1};
    int n1 = sizeof(keys1) / sizeof(keys1[0]);
    struct Node* head1 = NULL;
    for (int i = n1 - 1; i >= 0; i--)
    {
        push(&head1, keys1[i]);
    }




    int keys2[] = {5 ,0};
    int n2 = sizeof(keys2) / sizeof(keys2[0]);
    struct Node* head2 = NULL;
    for (int i = n2 - 1; i >= 0; i--)
    {
        push(&head2, keys2[i]);
    }

   int k1=0,k2=0;//45   367

    if (n1>n2)
    k1=n1-n2;
    else if(n2>n1)
    k2=n2-n1;

   Node *a=paddingzero(head1,k2);
   Node *b=paddingzero(head2,k1);

       printList(a);

       printList(b);




  subtract(a,b);

}
