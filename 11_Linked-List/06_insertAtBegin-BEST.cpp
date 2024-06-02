#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node *next;
     Node(int x)
     {
          data = x;
          next = NULL;
     }
};

Node *insertAtBegin(Node *head, int data)
{
     Node *temp = new Node(data);
     temp->next=head;

     return temp;
}

Node printList(Node *head)
{
     Node *current=head;
     while (current!=NULL)
     {
          cout<<current->data<<" ";
          current=current->next;
     }
}

int main()
{
     Node *head = NULL;
     head=insertAtBegin(head, 30);
     head=insertAtBegin(head, 20);
     head=insertAtBegin(head, 10);
     printList(head);

     return 0;
}