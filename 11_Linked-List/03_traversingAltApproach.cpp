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
     while (head!=NULL)
     {
          cout<<head->data<<" ";
          head=head->next;
     }
}

int main()
{
     Node *head = new Node(10);

     traverseList(head);
     traverseList(head);
     //It will print the value "10" two times, as only the address, ie, a copy of the value is passed while passing it as pointer, hence the actual value (10) does not get affected after the first funciton call.

     return 0;
}