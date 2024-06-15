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

void printCircularLL(Node *head)
{
     if (head == NULL)
          cout << "NULL";
     if (head->next == head)
          cout << head->data;

     cout << head->data << " ";
     Node *current = head->next;
     while (current != head)
     {
          cout << current->data << " ";
          current = current->next;
     }

     cout << endl;

     return;
}

Node *insertAtEndCLL(Node *head, int x)
{
     Node *newEnd = new Node(x);
     if (head == NULL)
     {
          newEnd->next = newEnd;
          return newEnd;
     }

     Node *curr = head;
     while (curr->next != head)
          curr = curr->next;

     newEnd->next = head->next;
     head->next = newEnd;
     newEnd->data = head->data;
     head->data = x;

     return newEnd;
}

int main()
{
     Node *head = new Node(10);
     Node *temp1 = new Node(20);
     Node *temp2 = new Node(30);
     int x = 5;
     head->next = temp1;
     temp1->next = temp2;
     temp2->next = head;
     printCircularLL(head);

     head = insertAtEndCLL(head, x);
     printCircularLL(head);

     return 0;
}