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

void leftView(TreeNode* root, int level, int *maxLevel)
{
     if (root==NULL) { return; }
     if (*maxLevel<level) {
          cout<<root->data<<" ";
          *maxLevel=level;
     }

     leftView(root->left, level+1, maxLevel);
     leftView(root->right, level+1, maxLevel);

     return;
}

int main()
{
     TreeNode *root=new TreeNode(10);
     root->left=new TreeNode(20);
     root->right=new TreeNode(30);
     root->left->left=new TreeNode(40);
     root->left->right=new TreeNode(50);
     int maxLevel=0;

     leftView(root, 1, &maxLevel);

     return 0;
}