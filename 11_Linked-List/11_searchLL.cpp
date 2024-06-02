// Time: O(n), for both iterative and recursive, so time comp is upper bounded by θ(n)
// Space: O(1) for iterative, O(n) for recursive
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

int searchLL(Node *head, int key)
{
     int pos = 1;
     Node *current = head;

     while (current) //while (current!=NULL)
     {
          if (current->data == key)
          {
               return pos;
          }
          else
          {
               pos += 1;
               current = current->next;
          }
     }

     return -1;
}

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

int main()
{
     Node *head = NULL;
     head = insertAtEnd(head, 10);
     head = insertAtEnd(head, 5);
     head = insertAtEnd(head, 20);
     head = insertAtEnd(head, 15);
     int key = 20;

     cout << searchLL(head, key);

     return 0;
}