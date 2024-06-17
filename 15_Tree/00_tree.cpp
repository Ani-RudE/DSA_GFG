#include <iostream>
using namespace std;

struct Node {
     int data;
     Node* right;
     Node* left;
     Node (int x)
     {
          data=x;
          left=NULL;
          right=NULL;
     }
};

int main()
{
     Node *root=new Node(10);
     root->left=new Node(20);
     root->right=new Node(30);
     root->left->left=new Node(40);
     root->left->right=new Node(50);

     return 0;
}