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

TreeNode* pre=NULL;

TreeNode* toDoublyLinkedList(TreeNode* root) {
     if (root==NULL) { return root; }

     TreeNode* head=toDoublyLinkedList(root->left);

     if (pre==NULL) {
          head=root;
     } else {
          root->left=pre;
          pre->right=root;
     }

     pre=root;
     root=toDoublyLinkedList(root->right);

     return head;
}

TreeNode printList(TreeNode *head)
{
     if (head == NULL)
          cout << "NULL" << endl;

     TreeNode *current = head;
     while (current != NULL)
     {
          cout << current->data << " ";
          current = current->right;
     }
}

int main()
{
     TreeNode *root=new TreeNode(10);
     root->left=new TreeNode(5);
     root->right=new TreeNode(20);
     root->right->left=new TreeNode(30);
     root->right->right=new TreeNode(35);
     TreeNode* head=toDoublyLinkedList(root);
     printList(head);

     return 0;
}