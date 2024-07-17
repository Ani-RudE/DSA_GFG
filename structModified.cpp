#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
     string name;                       // name of the node
     int lockedBy;                      // store locked by which id
     bool isLocked;                     // is node locked or not
     vector<TreeNode *> childs;         // store all children of the current node
     TreeNode *parent;                  // parent of the current node
     set<TreeNode *> lockedDescendents; // store node pointer of locked descendants

     TreeNode(string nm, TreeNode *par)
     {
          // constructor to create node by passing node's name and partner node pointer.
          // if current node is the root node of the tree then the parent of the root will be NULL
          name = nm;
          lockedBy = -1; // Initially we are assuming the current node is not locked by any id (-1 means not locked by any id)
          parent = par;
          isLocked = false; // node is unlocked
     }

     void addChild(vector<string> &a)
     {
          // create all the children of the current node
          for (string &nm : a)
          {
               childs.push_back(new TreeNode(nm, this));
          }
     }
};

struct MAryTree
{
     TreeNode *root;                                          // root of the tree
     unordered_map<string, TreeNode *> nameToTreeNodeMapping; // store node name and node pointer mapping
     MAryTree(string name)
     {
          // constructor of M-Ary-Tree
          root = new TreeNode(name, nullptr);
     }
};

void makeMAryTree(MAryTree &tree, vector<string> &a, int m)
{
     // this method is used to build the tree (Initially).
     queue<TreeNode *> q; // using queue to iterate all nodes like BFS approach

     // Initialize variables
     int k = 1, i, n = a.size();

     // Push the root node into the queue to start the process
     q.push(tree.root);

     // Loop until there are no more nodes left in the queue
     while (!q.empty())
     {
          // Iterate node (pop node) and push all its children in the queue.
          TreeNode *r = q.front(); // Get the node at the front of the queue
          q.pop();                 // Remove the node from the queue

          // Map the node's name to its pointer in the tree's name-to-node mapping
          tree.nameToTreeNodeMapping[r->name] = r;

          // Create a temporary vector to store the names of the children nodes
          vector<string> b;

          // Add up to `m` children to the current node
          for (i = k; i < min(n, k + m); i++)
          {
               b.push_back(a[i]);
          }

          // Add these children to the current node
          r->addChild(b);

          // Insert all its children (of recently popped node) into the queue
          for (TreeNode *child : r->childs)
          {
               q.push(child);
          }

          // Update k to be the next index to consider in the array `a`
          k = i;
     }
}

void print(TreeNode *r)
{
     // method is used to print the tree (for debugging purposes).
     if (!r)
          return;
     cout << "TreeNode -> " << r->name << " " << r->lockedBy << " "
          << "\n";
     cout << "Childs -> \n";
     for (TreeNode *child : r->childs)
     {
          cout << "       " << child->name << "\n";
     }
     cout << "Locked -> \n";
     for (TreeNode *child : r->lockedDescendents)
     {
          cout << "       " << child->name << "\n";
     }
     for (TreeNode *child : r->childs)
     {
          print(child);
     }
}

void updateParents(TreeNode *r, TreeNode *curr)
{
     // inform all ancestors about its child locking in O(logN base M)
     // N is the total no of nodes in the tree
     // M - > M-ary-tree
     while (r)
     {
          r->lockedDescendents.insert(curr);
          r = r->parent;
     }
}

bool lock(MAryTree &tree, string name, int id)
{
     // method is required to lock the node which is given in the problem statement
     TreeNode *r = tree.nameToTreeNodeMapping[name]; // fetch the node pointer using its name
     if (r->isLocked || r->lockedDescendents.size())
          return false; // check if node is already locked and have any locked ancestor than return false (if any condition becomes true)
     TreeNode *par = r->parent;
     while (par)
     {
          // check if any ancestor is locked or not (by any id) if yes then we can't lock the current node
          if (par->isLocked)
               return false;
          par = par->parent;
     }
     updateParents(r->parent, r); // inform all ancestors about its locking in O(logm(n) time)
     r->isLocked = true;          // lock the node
     r->lockedBy = id;
     return true;
}

bool unlock(MAryTree &tree, string name, int id)
{
     TreeNode *r = tree.nameToTreeNodeMapping[name];
     if (!r->isLocked || r->lockedBy != id)
          return false; // return false if the node is unlocked or locked by a different id
     TreeNode *par = r->parent;
     while (par)
     {
          // inform all Ancestors about its unlocking
          par->lockedDescendents.erase(r);
          par = par->parent;
     }
     r->isLocked = false; // unlock it
     r->lockedBy = -1;
     return true;
}

bool upgradeLock(MAryTree &tree, string name, int id)
{
     TreeNode *r = tree.nameToTreeNodeMapping[name];
     if (r->isLocked || r->lockedDescendents.size() == 0)
          return false; // return false if the node is already locked or has 0 locked descendants
     for (TreeNode *ld : r->lockedDescendents)
     {
          // check all the descendants are locked by the same id or not
          if (ld->lockedBy != id)
               return false;
     }
     TreeNode *par = r->parent;
     while (par)
     {
          // check if any ancestor is locked or not
          if (par->isLocked)
               return false;
          par = par->parent;
     }
     set<TreeNode *> stt = r->lockedDescendents;
     for (TreeNode *ld : stt)
     {
          // unlock all descendants
          unlock(tree, ld->name, id);
     }
     lock(tree, name, id); // lock current node
     return true;
}

int main()
{
     int n, m, t, i, opType, id;
     string name;
     /*
          id: User ID
          opType: Lock (1), Unlock (2) or Upgrade (3)
          name: Node names
          i: Num of nodes
     */
     cin >> n >> m >> t;
     vector<string> a(n);
     for (i = 0; i < n; i++)
     {
          cin >> a[i];
     }
     MAryTree *tree = new MAryTree(a[0]);
     makeMAryTree(*tree, a, m);
     // tree->print(tree->root);
     while (t--)
     {
          cin >> opType >> name >> id;
          if (opType == 1)
          {
               if (lock(*tree, name, id))
               {
                    cout << "true";
               }
               else
                    cout << "false";
          }
          else if (opType == 2)
          {
               if (unlock(*tree, name, id))
               {
                    cout << "true";
               }
               else
                    cout << "false";
          }
          else if (opType == 3)
          {
               if (upgradeLock(*tree, name, id))
               {
                    cout << "true";
               }
               else
                    cout << "false";
          }
          cout << "\n";
     }
}
