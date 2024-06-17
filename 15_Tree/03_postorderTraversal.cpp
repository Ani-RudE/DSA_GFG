#include <iostream>
using namespace std;

struct Node
{
     int data;
     Node *right;
     Node *left;
     Node(int x)
     {
          data = x;
          left = NULL;
          right = NULL;
     }
};

void postorder(Node *root)
{
     if (root != NULL)
     {
          postorder(root->left);
          postorder(root->right);
          cout << root->data << " ";
     }
}

int main()
{
     Node *root = new Node(10);
     root->left = new Node(20);
     root->right = new Node(30);
     root->right->left = new Node(40);
     root->right->right = new Node(50);
     postorder(root);

     return 0;
}