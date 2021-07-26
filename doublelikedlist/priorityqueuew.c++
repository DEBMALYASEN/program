#include <bits/stdc++.h>
using namespace std;
class Node
{
    int info;
    int priority;
    Node *prev, *next;
    Node(int info,int priority)
    {
        this->info=info;
        this->priority=priority;
    }
};

void push(Node** front, Node** rear, int n, int p)
{
    Node* news = new Node(n,p);


    if (*front == NULL)
    {
        *front = new;
        *rear = new;
         new->next = NULL;
    }
    else
    {

        if (p <= (*front)->priority)
        {
            new->next = *front;
            (*front)->prev = new->next;
            *front = new;
        }
 
        // then insert after the rear.
        else if (p > (*rr)->priority) {
            news->next = NULL;
            (*rr)->next = news;
            news->prev = (*rr)->next;
            *rr = news;
        }

        // Handle other cases
        else {

            // Find position where we need to
            // insert.
            Node* start = (*fr)->next;
            while (start->priority > p)
                start = start->next;
            (start->prev)->next = news;
            news->next = start->prev;
            news->prev = (start->prev)->next;
            start->prev = news->next;
        }
    }
}


int peek(Node* front)
{
return front->info;
}

bool isEmpty(Node* front)
{
return (front == NULL);
}

int pop(Node** fr, Node** rr)
{
    Node* temp = *fr;
    int res = temp->info;
    (*fr) = (*fr)->next;
    free(temp);
    if (*fr == NULL)
        *rr = NULL;
    return res;
}

int main()
{
    Node *front = NULL, *rear = NULL;

    push(&front, &rear, 2, 3);
    push(&front, &rear, 3, 4);
    push(&front, &rear, 4, 5);
    push(&front, &rear, 5, 6);
    push(&front, &rear, 6, 7);
    push(&front, &rear, 1, 2);

    cout << pop(&front, &rear) << endl;
    cout << peek(front);

    return 0;
}
