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

Node *insertAtEndDLL(Node *head, int data)
{
     Node *temp = new Node(data);

     if (head == NULL)
          return temp;
     
     Node *current = head;
     while (current->next != NULL)
     {
          current = current->next;
     }

     current->next = temp;
     temp->prev = current;
     
     return head;
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
     int data = 50;
     printList(head);
     cout << endl;

     head = insertAtEndDLL(head, data);
     printList(head);

     return 0;
}