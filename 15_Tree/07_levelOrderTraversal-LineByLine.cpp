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

void levelOrderLineByLine (TreeNode* root) {
     if (root==NULL) { return; }

     queue<TreeNode*> q;
     q.push(root);
     q.push(NULL);

     while (q.size()>1) {
          TreeNode* curr=q.front();
          q.pop();
          if (curr==NULL) {
               cout<<endl;
               q.push(NULL);
               continue;
          }

          cout<<curr->data<<" ";

          if (curr->left!=NULL) {
               q.push(curr->left);
          }
          if (curr->right!=NULL) {
               q.push(curr->right);
          }
     }

     return;
}

int main()
{
     TreeNode *root=new TreeNode(10);
     root->left=new TreeNode(20);
     root->right=new TreeNode(30);
     root->left->left=new TreeNode(40);
     root->left->right=new TreeNode(50);

     levelOrderLineByLine(root);

     return 0;
}