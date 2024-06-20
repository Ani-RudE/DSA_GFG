#include <iostream>
using namespace std;

struct TreeNode {
     int data;
     TreeNode* right;
     TreeNode* left;
     TreeNode (int x)
     {
          data=x;
          left=NULL;
          right=NULL;
     }
};

int maxInBT(TreeNode* root)
{
     if (root==NULL)
          return INT32_MIN;
          
     return (max(root->data, (max(maxInBT(root->left), maxInBT(root->right)))));
}

int main()
{
     TreeNode *root=new TreeNode(10);
     root->left=new TreeNode(20);
     root->right=new TreeNode(30);
     root->left->left=new TreeNode(40);
     root->left->right=new TreeNode(50);

     cout<<maxInBT(root);

     return 0;
}