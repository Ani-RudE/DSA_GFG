#include <bits/stdc++.h>
using namespace std;

// void getNodeNames(vector<string> &nodeNames, int n) {

// }

struct TreeNode {
     string nameOfNode;
     int lockedUserID;
     bool checkLock;
     vector<TreeNode*> children;
     TreeNode* parent;
     vector<TreeNode*> lockedChildren; //D#1 - Maybe set?

     TreeNode (string s, TreeNode* temp) {
          nameOfNode = s;
          parent = temp;
          lockedUserID = -1;
          checkLock = false;
     }

     void pushChildren(vector<string> &childNodes) {
          for (string &x : childNodes) {
               TreeNode* temp = new TreeNode(x, this); //OPT#1
               children.push_back(temp);
          }
     }
};

struct NAryTree {
     TreeNode* root;
     map<string, TreeNode*> nodeNameMap; //#D2 - Maybe use map as global //OPT#3 - Use unordered_map
     NAryTree(string nodeName) {
          root = new TreeNode(nodeName, NULL);
     }
};

void constructNAryTree (NAryTree &tree, vector<string> &nodeNames, int m) {
     queue<TreeNode* > q;
     int i, idx = 1; //OPT#2
     int n = nodeNames.size();
     q.push(tree.root);
     while (q.size()!=0) {
          TreeNode *curr = q.front();
          q.pop();
          tree.nodeNameMap[curr->nameOfNode] = curr;
          vector<string> tempChild;
          for (i = idx; i < min(n, idx+m); ++i) { //OPT#2
               tempChild.push_back(nodeNames[i]);
          }

          curr->pushChildren(tempChild);
          for (TreeNode* x : curr->children) {
               q.push(x);
          }
          
          idx = i; //OPT#2
     }

     return;
}

void notifyLockToParents(TreeNode *curr, TreeNode* currParent) {
     while (currParent != NULL) {
          currParent->lockedChildren.push_back(curr);
          currParent = currParent->parent;
     }
}

bool lockNode(NAryTree &tree, string lockNodeName, int userID) {
     TreeNode *curr =  tree.nodeNameMap[lockNodeName];
     int numOfLockChild = curr->lockedChildren.size();
     if (curr->checkLock == true || numOfLockChild > 0) {
          return false;
     }

     TreeNode* parentNode = curr->parent;
     while (parentNode != NULL) {
          if (parentNode->checkLock == true) { return false; }
          parentNode = parentNode->parent;
     }

     notifyLockToParents(curr, curr->parent);

     curr->lockedUserID = userID;
     curr->checkLock = true;
     return true;
}

bool unlockNode(NAryTree &tree, string unlockNodeName, int userID) {
     TreeNode* curr = tree.nodeNameMap[unlockNodeName];
     if (curr->checkLock==false || curr->lockedUserID != userID) { //curr->checkLock==true
          return false;
     }

     TreeNode* parentNode =  curr->parent;
     while (parentNode != NULL)
     {
          // Inform all ancestors about its unlocking
          auto it = find(parentNode->lockedChildren.begin(), parentNode->lockedChildren.end(), curr);
          if (it != parentNode->lockedChildren.end()) {
               parentNode->lockedChildren.erase(it);
          }
          parentNode = parentNode->parent;
     }

     curr->checkLock = false;
     curr->lockedUserID = -1;

     return true;
}

bool upgradeLockedNode(NAryTree &tree, string upgradeNodeName, int userID) {
     TreeNode* curr = tree.nodeNameMap[upgradeNodeName];
     if (curr->checkLock == true || curr->lockedChildren.size() == 0) {
          return false;
     }

     for (TreeNode* x : curr->lockedChildren) {
          if (x->lockedUserID != userID) { return false; }
     }

     TreeNode* parentNode = curr->parent;
     while (parentNode != NULL) {
          if (parentNode->checkLock == true) { return false; }
          parentNode = parentNode->parent;
     }

     vector<TreeNode*> v = curr->lockedChildren;
     for (TreeNode* x : v) {
          unlockNode(tree, x->nameOfNode, userID);
     }

     lockNode(tree, upgradeNodeName, userID);

     return true;
}

void solution(NAryTree* tree, int &queryID, string &nameOfNode, int &userID) {
          if (queryID== 1) {
               if (lockNode(*tree, nameOfNode, userID)) {
                    cout << "true";
               } else {
                    cout << "false";
               }
          } else if (queryID== 2) {
               if (unlockNode(*tree, nameOfNode, userID)) {
                    cout << "true";
               } else {
                    cout << "false";
               }
          } else if (queryID== 3) {
               if (upgradeLockedNode(*tree, nameOfNode, userID)) {
                    cout << "true";
               } else {
                    cout << "false";
               }
          }
          cout<<endl;

          return;
}

int main() {
     int n, m, numChild, T, queryID, uID;
     string nameOfNode;

     cin>>n>>m>>numChild>>T;
     vector<string> nodeNames(n);
     // getNodeNames(nodeNames, n);
     for (int i=0; i<n; ++i) {
          cin>>nodeNames[i];
     }

     NAryTree* tree = new NAryTree(nodeNames[0]);
     constructNAryTree(*tree, nodeNames, m);

     while (T--) {
          cin>>queryID;
          cin>>nameOfNode;
          cin>>uID;

          solution(tree, queryID, nameOfNode, uID);
     }

     return 0;
}