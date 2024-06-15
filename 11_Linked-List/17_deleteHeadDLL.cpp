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

Node* removeHeadDLL(Node* head)
{
     if (head==NULL)
          return NULL;
     if (head->next==NULL)
     {
          delete head;
          return NULL;
     }
     
     Node* curr=head->next;
     head->next=NULL;
     curr->prev==NULL;
     delete head;

     return curr;
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

     head=removeHeadDLL(head);
     cout<<head->prev<<" ";
     printList(head);

     return 0;
}