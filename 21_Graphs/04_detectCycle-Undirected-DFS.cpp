#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isCycleUndirectedDFS(unordered_map<int, vector<int>> &adj, int u, unordered_map<int, bool> &visited, int parent)
{
     visited[u] = true;

     for (auto &x : adj[u])
     {
          if (x == parent)
          {
               continue;
          }
          if (visited[x] == true)
          {
               return true;
          }

          if (isCycleUndirectedDFS(adj, x, visited, u))
          {
               return true;
          }
     }

     return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, unordered_map<int, vector<int>> &adj) {
     unordered_map<int, bool> visited;
     for (int i = 1; i <= V; ++i) {
          if (!visited[i] && isCycleUndirectedDFS(adj, i, visited, -1)) {
               return true;
          }
     }

     return false;
}

int main() {
     int V, E;
     cin >> V >> E;
     unordered_map<int, vector<int>> adj;
     for (int i = 0; i < E; ++i) {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     bool ans = isCycle(V, adj);
     if (ans)
          cout << "1\n";
     else
          cout << "0\n";

     return 0;
}

/*
For Input: 
5 5
0 1
1 2
1 4
2 3
3 4

Expected Output: 
1
*/