//Auxilary Space: θ(width) or O(n)
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

void levelOrderLineByLine2 (TreeNode* root) {
     if (root==NULL) { return; }

     queue<TreeNode*> q;
     q.push(root);

     while (q.empty()==false) {
          int n=q.size(); //Taking the `n` variable seperate coz if we put the `i < q.count()` condition directly inside the loop, then the loop will not iterate properly because the value of `q.count()` will keep on chaning on every loop iteration. Hence, the new line will not be added at the correct places.
          for (int i=0; i<n; ++i) {
               TreeNode* curr=q.front();
               q.pop();
               cout<<curr->data<<" ";
               
               if (curr->left!=NULL) {
                    q.push(curr->left);
               }
               if (curr->right!=NULL) {
                    q.push(curr->right);
               }
          }
          cout<<endl;
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

     levelOrderLineByLine2(root);

     return 0;
}