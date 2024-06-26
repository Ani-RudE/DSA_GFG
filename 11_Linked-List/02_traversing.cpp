// Time: O(N)
// Space: O(1), where N = Number of nodes
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

Node traverseList(Node *head)
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
     Node *temp3 = new Node(40);
     head->next = temp1;
     temp1->next = temp2;
     temp2->next = temp3;

     traverseList(head);

     return 0;
}