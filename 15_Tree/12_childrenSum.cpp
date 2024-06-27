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

bool isCSum(TreeNode* root) {
     if (root==NULL) { return true; }

     if (root->left==NULL && root->right==NULL) { return true; }
     int sum=0;

     if (root->left!=NULL) {
          sum+=root->left->data;
     }

     if (root->right!=NULL) {
          sum+=root->right->data;
     }

     return ((sum==root->data) && isCSum(root->left) && isCSum(root->right));
}

int main()
{
     TreeNode *root=new TreeNode(20);
     root->left=new TreeNode(8);
     root->right=new TreeNode(12);
     root->right->left=new TreeNode(3);
     root->right->right=new TreeNode(9);
     cout<<isCSum(root)<<endl;

     TreeNode *root2=new TreeNode(10);
     root2->left=new TreeNode(20);
     root2->right=new TreeNode(30);
     root2->left->left=new TreeNode(40);
     root2->left->right=new TreeNode(50);
     cout<<isCSum(root2);

     return 0;
}