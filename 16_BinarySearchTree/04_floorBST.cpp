#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x)
     {
          data = x;
          left = right = NULL;
     }
};

void printInorder(TreeNode *root) {
     if (root != NULL)
     {
          printInorder(root->left);
          cout << root->data << " ";
          printInorder(root->right);
     }
}

int main()
{
     TreeNode *root = new TreeNode(50);
     root->left = new TreeNode(30);
     root->right = new TreeNode(70);
     root->left->left = new TreeNode(20);
     root->left->right = new TreeNode(40);
     root->right->left = new TreeNode(18);
     root->right->left->left = new TreeNode(16);
     root->right->right = new TreeNode(80);
     printInorder(root);
     

     return 0;
}