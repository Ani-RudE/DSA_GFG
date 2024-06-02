#include <bits/stdc++.h>
using namespace std;

struct Node
{
     int data;
     Node *next; //Self referential
     Node (int x) //Using a constructor to assign default values to a node
     {
          data=x;
          next=NULL;
     }
};


int main()
{
     Node *head = new Node(10);
     Node *temp1 = new Node(20);
     Node *temp2 = new Node(30);
     head->next=temp1;
     temp1->next=temp2;

     // Node *head = new Node(10);
     // Node *temp2 = new Node(30);
     // head->next->next=new Node(30);

     return 0;
}