#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node* root)
{
     if (root==NULL) { return; }
     queue<Node*> q;
     q.push(root);

     while (q.empty()==false)
     {
          Node* curr=q.front();
          q.pop();
          cout<<curr->data<<" ";
          if (curr->left!=NULL)
               q.push(curr->left);
          if (curr->right!=NULL)
               q.push(curr->right);
     }

     return;
}

int main()
{
     Node *root=new Node(8);
     root->right=new Node(6);
     root->right->left=new Node(2);
     root->right->right=new Node(4);
     root->right->right->left=new Node(3);

     levelOrderTraversal(root);

     return 0;
}