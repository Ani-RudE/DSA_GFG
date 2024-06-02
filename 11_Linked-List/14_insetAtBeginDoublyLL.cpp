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

Node *insertAtBeginDLL(Node *head, int data)
{
     Node *temp=new Node(data);
     temp->next=head;         

     if (head!=NULL)
     {
          head->prev=temp;
     }

     return temp;
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
     int data=5;
     printList(head);
     cout<<endl;

     head=insertAtBeginDLL(head, data);
     printList(head);

     return 0;
}