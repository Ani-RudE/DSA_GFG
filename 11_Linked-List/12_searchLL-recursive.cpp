// Time: O(n), for both iterative and recursive, so time comp is upper bounded by θ(n)
// Space: O(n) for recursive, O(1) for iterative
#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;-
     Node *next;
     Node(int x)
     {
          data = x;
          next = NULL;
     }
};

int searchLLrecursive(Node *head, int key)
{
     if (head==NULL)
          return -1;
     if (head->data==key)
          return 1;
     else
     {
          int pos=searchLLrecursive(head->next, key);
          if (pos==-1)
               return -1;
          else
               return pos+1;
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

     cout << searchLLrecursive(head, key);

     return 0;
}