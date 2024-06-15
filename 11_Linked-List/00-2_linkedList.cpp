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

void printList(Node *head)
{
     if (head == NULL)
          cout << "NULL" << endl;

     Node *current = head;
     while (current != NULL)
     {
          cout << current->data << " ";
          current = current->next;
     }

     cout << endl;

     return;
}

int main()
{
     Node *head = NULL;
     head = insertAtEnd(head, 10);
     head = insertAtEnd(head, 20);
     head = insertAtEnd(head, 30);
     head = insertAtEnd(head, 40);
     head = insertAtEnd(head, 50);
     printList(head);

     return 0;
}