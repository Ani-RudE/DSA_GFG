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

void kthDistance(Node* root, int k)
{
     if (root!=NULL && k>0)
     {
          kthDistance(root->left, k-1);
          kthDistance(root->right, k-1);
     }
     else if (root!=NULL && k==0)
          cout<<root->data<<" ";
     
     return;
}

int main()
{
     Node *root=new Node(10);
     root->left=new Node(20);
     root->right=new Node(30);
     root->left->left=new Node(40);
     root->left->right=new Node(50);
     root->right->right=new Node(70);
     root->right->right->right=new Node(80);
     int k=2;

     kthDistance(root,k);

     return 0;
}