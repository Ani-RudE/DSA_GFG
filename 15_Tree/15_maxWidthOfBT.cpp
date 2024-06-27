#include <iostream>
#include <queue>
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

int maxwidthBT(TreeNode* root) {
     if (root==NULL) { return 0; }
     else if (root->left==NULL && root->right==NULL) {
          return 1;
     }
                                                                      
     queue<TreeNode*> q;
     q.push(root);
     int res=0;

     while (q.empty()==false) {
          int n=q.size();
          res=max(res, n);
          
          for (int i=0; i<n; ++i) {
               TreeNode* curr=q.front();
               q.pop();

               if (curr->left!=NULL) {
                    q.push(curr->left);
               }
               if (curr->right!=NULL) {
                    q.push(curr->right);
               }
          }
     }

     return res;
}

int main()
{
     TreeNode *root=new TreeNode(10);
     root->left=new TreeNode(20);
     root->right=new TreeNode(30);
     root->left->left=new TreeNode(40);
     root->left->right=new TreeNode(50);
     root->right->left=new TreeNode(60);
     cout<<maxwidthBT(root);

     return 0;
}