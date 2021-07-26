#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}
int GetNth(Node* head, int index)
{

    Node* current = head;

    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

}


Node* identifyCycle(Node* head)
{

    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
 s
        fast = fast->next->next;

        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}
//slow ponts to a node in ccle
void removeCycle(Node* slow, Node* head)
{

    int k = 1;
    for (Node* ptr = slow; ptr->next != slow; ptr = ptr->next)
        k++;



    Node* curr = head;
    for (int i = 0; i < k; i++)
        curr = curr->next;




    Node* prev = nullptr;
    while (curr != head)
    {
        prev = curr;
        curr = curr->next;
        head = head->next;
    }

    prev->next = nullptr;
}















void printNthFromLast(struct Node *head, int n)
{
  struct Node *main_ptr = head;
  struct Node *ref_ptr = head;

  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    } ]
     if(ref_ptr == NULL)
     {
        head = head->next;
        if(head != NULL)
            printf("Node no. %d from last is %d ", n, main_ptr->data);
     }
     else
     {
       while(ref_ptr != NULL)
       {
          main_ptr = main_ptr->next;
          ref_ptr  = ref_ptr->next;
       }
       printf("Node no. %d from last is %d ", n, main_ptr->data);
     }
  }
}
int countNodesinLoop(struct Node *list)
{
    struct Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p &&
                     fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

    /
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }

    return 0;
}
int countNodes(struct Node *n)
{
    int res = 1;
    struct Node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}
void printList(struct Node* ptr)
{
    while (ptr != NULL) {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
bool compareLists(struct Node* head1, struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    if (temp1 == NULL && temp2 == NULL)
        return 1;

    return 0;
}
void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void rotate(Node** head_ref, int k)
{
    if (k == 0)
        return;
    Node* current = *head_ref;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    current = *head_ref;

    for (int i = 1; i < k ; i++)
        current = current->next;

    *head_ref = current->next;
    current->next = NULL;
}
void removeDuplicates(Node** head_ref)
{

    Node* current = *head_ref;
    Node* next_next;
    if (current == NULL)
    return;

    while (current->next != NULL)
    {
    if (current->data == current->next->data)
    {
        next_next = current->next->next;
        free(current->next);
        current->next = next_next;
    }
    else /* This is tricky: only advance if no deletion */
    {
        current = current->next;
    }
    }

}
void removeDuplicates(struct Node *start)
{
    unordered_set<int> seen;


    struct Node *curr = start;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}
void pairWiseSwap(Node* head)
{
    Node* temp = head;
    while (temp != NULL && temp->next != NULL)
     {


        swap(temp->data,temp->next->data);

        1temp = temp->next->next;
    }
}




void moveToFront(Node **head_ref)
{


    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    Node *secLast = NULL;
    Node *last = *head_ref;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}




 Node* sortedIntersect(  Node* a, Node* b)
{

   if (a == NULL || b == NULL)
       return NULL;

   if (a->data < b->data)
       return sortedIntersect(a->next, b);

   if (a->data > b->data)
       return sortedIntersect(a, b->next);
   Node* temp = new Node();
   temp->data = a->data;
   temp->next = sortedIntersect(a->next, b->next);
   return temp;
}
Node* intersectPoint(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;


    if (ptr1 == NULL || ptr2 == NULL)
    {

        return NULL;
    }


    while (ptr1 != ptr2)
     {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;


        if (ptr1 == ptr2)
         {

            return ptr1;
        }

        if (ptr1 == NULL)

  {
            ptr1 = head2;
        }

        if (ptr2 == NULL)
        {

            ptr2 = head1;
        }
    }

    return ptr1;
}
void segregateEvenOdd(struct Node **head_ref)
{

    Node *evenStart = NULL;

    Node *evenEnd = NULL;

    Node *oddStart = NULL;

    Node *oddEnd = NULL;

    Node *currNode = *head_ref;

    while(currNode != NULL)
    {
        int val = currNode -> data;

        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
            }

            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        }


        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }

        // Move head pointer one step in
        // forward direction
        currNode = currNode -> next;
    }s

    // If either odd list or even list is empty,
    // no change is required as all elements
    // are either even or odd.
    if(oddStart == NULL || evenStart == NULL){
        return;
    }

    // Add odd list after even list.
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;

    // Modify head pointer to
    // starting of even list.
    *head_ref = evenStart;
}

struct Node* Reverse(struct Node* head, int k)
{
  // Create a stack of Node*
  stack<Node*> mystack;
  struct Node* current = head;
  struct Node* prev = NULL;

  while (current != NULL) {

      // Terminate the loop whichever comes first
      // either current == NULL or count >= k
      int count = 0;
      while (current != NULL && count < k) {
          mystack.push(current);
          current = current->next;
          count++;
      }

      // Now pop the elements of stack one by one
      while (mystack.size() > 0) {

          // If final list has not been started yet.
          if (prev == NULL) {
              prev = mystack.top();
              head = prev;
              mystack.pop();
          } else {
              prev->next = mystack.top();
              prev = prev->next;
              mystack.pop();
          }
      }
  }

  // Next of last element will point to NULL.
  prev->next = NULL;

  return head;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */




void construct(Node* &head, string &s1, string &s2)
{

    if (head == nullptr) {
        return;
    }

    s1 += head->data;
    construct(head->next, s1, s2);
    s2 += head->data;
}

bool isPalindrome(Node* head)
{
    string s1, s2;
    construct(head, s1, s2);

    return s1 == s2;
}
void deleteNodes(struct Node *head, int m, int n)
{
    /
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *prev = NULL, *next = NULL;
    struct Node* curr = head;

    for (int i = 1; curr && i <= m; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    for (int i = 1; curr && i <= n; i++)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    prev->next = curr;

    deleteNodes(curr, m, n);
}






















int main()
{
    Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}

// This is code i
