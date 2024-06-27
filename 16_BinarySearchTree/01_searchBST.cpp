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

bool searchBST(TreeNode* root, int key) {
     while (root!=NULL) {
          if (root->data == key) {
               return true;
          } else if (root->data > key) {
               root=root->left;
          } else {
               root=root->right;
          }
     }

     return false;
}

int main()
{
     TreeNode *root = new TreeNode(15);
     root->left = new TreeNode(5);
     root->right = new TreeNode(20);
     root->left->left = new TreeNode(3);
     root->right->left = new TreeNode(18);
     root->right->left->left = new TreeNode(16);
     root->right->right = new TreeNode(80);
     int key=16;
     cout<<searchBST(root, key);

     return 0;
}