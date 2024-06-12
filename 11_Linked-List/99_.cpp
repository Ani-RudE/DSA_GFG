#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node *next;
     Node *prev;
     Node (int x)
     {
          data=x;
          next=NULL;
          prev=NULL
     }
};

Node *insertAtEnd(Node *head, int data)
{
     if (head==NULL)
     {
          head=new Node(data);
          return head;
     }
     
     Node *curr=head;
     while (curr->next!=NULL)
          curr=curr->next;
     
     Node *newNode=new Node(data);
     curr->next=newNode;

     return head;
}

void printList(Node *head)
{
     if (head==NULL)
          return;
     
     Node *curr=head;
     while (curr!=NULL)
     {
          cout<<curr->data<<" ";
          curr=curr->next;
     }

     return;
}


int main()
{
     Node *head=new Node(10);
     head=insertAtEnd(head, 20);
     head=insertAtEnd(head, 30);
     head=insertAtEnd(head, 40);
     head=insertAtEnd(head, 50);

     printList(head);

     return 0;
}