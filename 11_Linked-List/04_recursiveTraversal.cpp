// Time: O(N)
// Space: O(N), where N = Number of nodes
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

void traverseList(Node *current)
{
     if (current == NULL)
     {
          return;
     }

     cout << current->data << " ";
     traverseList(current->next);
}
// This version explicitly checks if current is NULL at the beginning, which serves as the base case for the recursion, ensuring it stops when it reaches the end of the list. It also changes the return type to void, as the function does not need to return a Node.

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
     cout << endl;

     Node *head2 = new Node(10);
     traverseList(head2);
     cout << endl;

     Node *head3 = NULL;
     traverseList(head3);

     return 0;
}

/*
The traverseList2() function in your code snippet is attempting to traverse a linked list and print out the data held in each Node. However, there are a few issues with the function as it stands:

Return Type: The function is declared to return a Node, but it does not return any value in any of its execution paths. This will lead to a compilation error. Since the purpose of this function is to traverse and print the list, it does not need to return anything. Therefore, its return type should be void.

Base Case Missing: The recursive call to traverseList2(current->next); will execute unconditionally if current is not NULL, which means it lacks a proper base case to terminate recursion when it reaches the end of the list. This oversight won't lead to a runtime error because the base case check (if (current!=NULL)) is performed at the beginning of the function, but it's not optimal in terms of clarity and efficiency. The recursion should only proceed if there's a next node to process.


     Node traverseList2(Node *current)
     {
          if (current!=NULL)
          {
               cout<<current->data<<" ";
          }

          traverseList2(current->next);
     }
*/