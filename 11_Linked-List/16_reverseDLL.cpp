#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node *prev;
     Node *next;
     Node(int d)
     {
          data = d;
          prev = NULL;
          next = NULL;
     }
};

Node *reverseDLL(Node *head)
{
     if (head==NULL || head->next==NULL)
          return head;
     
     Node *temp=NULL;
     Node *current=head;
     while (current!=NULL)
     {
          temp=current->prev;
          current->prev=current->next;
          current->next=temp;
          current=current->prev;

          // current->prev=temp->next;
          // current->next=temp->prev;
          // current=current->next;
     }

     return temp->prev;
     // return current;
}

Node printList(Node *head)
{
     if (head == NULL)
          cout << "NULL" << endl;

     Node *current = head;
     while (current != NULL)
     {
          cout << current->data << " ";
          current = current->next;
     }
}

int main()
{
     Node *head = new Node(10);
     Node *temp1 = new Node(20);
     Node *temp2 = new Node(30);
     head->next = temp1;
     temp1->prev = head;
     temp1->next = temp2;
     temp2->prev = temp1;
     printList(head);
     cout<<endl;

     head=reverseDLL(head);
     printList(head);

     return 0;
}