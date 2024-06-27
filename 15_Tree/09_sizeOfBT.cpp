#include <iostream>
using namespace std;

struct TreeNode
{
     int data;
     TreeNode *right;
     TreeNode *left;
     TreeNode(int x)
     {
          data = x;
          left = NULL;
          right = NULL;
     }
};

void sizeOfBT(TreeNode *root, int *size)
{
     if (root != NULL)
     {
          *size+=1;
          sizeOfBT(root->left, size);
          sizeOfBT(root->right, size);
     }
}

int getSize(TreeNode* root)
{
     if (root==NULL) { return 0; }
     else {
          return 1 + getSize(root->left) + getSize(root->right);
     }
}

int main()
{
     TreeNode *root = new TreeNode(10);
     root->left = new TreeNode(20);
     root->right = new TreeNode(30);
     root->right->left = new TreeNode(40);
     root->right->right = new TreeNode(50);
     
     int size=0;
     sizeOfBT(root, &size);
     cout<<size;

     return 0;
}