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

Node *insertAtPosition(Node *head, int position, int value)
{
     Node *newNode = new Node(value);
     if (position==1)
     {
          newNode->next=head;
          return newNode;
     }
     else if (position<=0)
     {
          cout<<"Position not available<<"<<endl;
          return head;
     }

     Node *current = head;

     for (int i = 1; i < position-1; ++i)
     {
          if (current != NULL)
               current = current->next;
          else
          {
               cout<<"Position not available"<<endl;
               return head;
          }
     }

     if (current==NULL)
     {
          cout<<"Position not available"<<endl;
          return head;
     }

     Node *temp = current->next;
     current->next = newNode;
     newNode->next = temp;

     return head;
}

//Approach given in video
/*
     Node *insertPos(Node *head, int pos, int data)
     {
          Node *temp=new Node(data);
          if (pos==1)
          {
               temp->next=head;
               return temp;
          }

          Node *current=head;
          for (int i=0; i<=pos-2 && current!=NULL; i++)
          {
               current=current->next;
          }

          if (current=NULL)
               return head;

          temp->next=current->next;
          current->next=temp;

          return head;
     }
*/

Node *insertAtEnd(Node *head, int data)
{
     Node *temp = new Node(data);

     if (head == NULL)
     {
          return temp;
     }
     else
     {
          Node *current = head;
          while (current->next != NULL)
          {
               current = current->next;
          }

          current->next = temp;

          return head;
     }
}

Node printList(Node *head)
{
     Node *current = head;
     while (current != NULL)
     {
          cout << current->data << " ";
          current = current->next;
     }
}

int main()
{
     Node *head = NULL;
     head = insertAtEnd(head, 10);
     head = insertAtEnd(head, 20);
     head = insertAtEnd(head, 30);
     head = insertAtEnd(head, 40);
     head = insertAtEnd(head, 50);

     int position = 5, value = 45;

     head = insertAtPosition(head, position, value);
     printList(head);

     return 0;
}