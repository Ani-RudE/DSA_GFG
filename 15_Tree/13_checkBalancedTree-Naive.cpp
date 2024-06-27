//Time: O(n^2)
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

int heightBT(TreeNode* root)
{
     if (root==NULL)
          return 0;
     else
          return (max(heightBT(root->left), heightBT(root->right))+1);
}

bool checkBalancedTree(TreeNode *root)
{
     if (root==NULL) { return true; }

     int l=heightBT(root->left);
     int r=heightBT(root->right);

     // return (l==r);

     // return ((l==r) && checkBalancedTree(root->left) && checkBalancedTree(root->right));

     return ((abs(l-r)<=1) && checkBalancedTree(root->left) && checkBalancedTree(root->right));
}

int main()
{
     TreeNode *root = new TreeNode(10);
     root->left = new TreeNode(20);
     root->right = new TreeNode(30);
     root->left->left = new TreeNode(40);
     root->left->right = new TreeNode(50);
     cout<<checkBalancedTree(root)<<endl;

     TreeNode *root2 = new TreeNode(10);
     root2->left = new TreeNode(20);
     root2->right = new TreeNode(30);
     root2->left->left = new TreeNode(40);
     root2->right->right = new TreeNode(50);
     root2->left->right = new TreeNode(60);
     root2->right->left = new TreeNode(70);
     cout<<checkBalancedTree(root2);

     return 0;
}