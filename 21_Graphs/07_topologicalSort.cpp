#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

void DFS(unordered_map<int, vector<int>> adj, int u, unordered_map<int, bool> &visited, stack<int> &stk) {
     visited[u] = true;

     for (auto &x: adj[u]) {
          if (visited[x]==false) {
               DFS(adj,x,visited,stk);
          }
     }

     stk.push(u);
}

// Function to detect cycle in an undirected graph.
vector<int> topoSort(int V, unordered_map<int, vector<int>> &adj)
{
     unordered_map<int, bool> visited;
     stack<int> stk;
     for (int i = 0; i < V; ++i)
     {
          visited[i] = false;
     }

     for (int i = 0; i < V; ++i) // Start from 0, not 1
     {
          if (!visited[i])
          {
               DFS(adj, i, visited, stk);
          }
     }

     vector<int> ans;
     while (stk.empty()!=true) {
          ans.push_back(stk.top());
          stk.pop();
     }

     return ans;
}

int main()
{
     int V, E;
     cin >> V >> E;
     unordered_map<int, vector<int>> adj;
     for (int i = 0; i < E; ++i)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
     }

     vector<int> res = topoSort(V,adj);
     for (int i=0; i<res.size(); ++i) {
          cout<<res[i]<<" ";
     }

     return 0;
}

/*
For Input:

Expected Output:
*/