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

void insertAtBegin(Node *begin, Node *head)
{
     begin->next=head;
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
     Node *head = new Node(10);
     Node *temp1 = new Node(20);
     Node *temp2 = new Node(30);
     head->next = temp1;
     temp1->next = temp2;

     Node *begin1=new Node(1);
     Node *begin2=new Node(2);
     Node *begin3=new Node(3);

     insertAtBegin(begin1, head);
     printList(begin1);
     cout<<endl;

     insertAtBegin(begin2, begin1);
     printList(begin2);
     cout<<endl;

     insertAtBegin(begin3, begin2);
     printList(begin3);
     cout<<endl;

     return 0;
}