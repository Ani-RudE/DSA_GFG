//Time: O(Height) as it traverses the BT
//Space: O(Height) extra space
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

TreeNode* getSuccessor(TreeNode* curr) {
     curr=curr->right;
     while (curr!=NULL && curr->left!=NULL) {
          curr=curr->left;
     }

     return curr;
}

TreeNode* delNode(TreeNode* root, int key) {
     if (root==NULL) { return root; }
     if (root->data>key) {
          root->left=delNode(root->left, key);
     }
     else if (root->data<key) {
          root->right=delNode(root->right, key);
     }
     else {
          if (root->left==NULL) {
               TreeNode* temp=root->right;
               delete root;
               return temp;
          } else if (root->right==NULL) {
               TreeNode* temp=root->left;
               delete root;
               return temp;
          } else {
               TreeNode* succ=getSuccessor(root);
               root->data=succ->data;
               root->right=delNode(root->right, succ->data);
          }
     }

     return root;
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
     printInorder(root);
     cout<<endl;

     delNode(root, 18);
     printInorder(root);

     return 0;
}
