#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isCycleDirectedDFS(unordered_map<int, vector<int>> &adj, int u, unordered_map<int, bool> &visited, unordered_map<int, bool> &inRecursion)
{
     visited[u] = true;
     inRecursion[u] = true;

     for (auto &x : adj[u])
     {
          if (!visited[x] && isCycleDirectedDFS(adj, x, visited, inRecursion))
          {
               return true;
          }
          else if (inRecursion[x] == true)
          {
               return true;
          }
     }

     inRecursion[u] = false;

     return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, unordered_map<int, vector<int>> &adj)
{
     unordered_map<int, bool> visited;
     unordered_map<int, bool> inRecursion;
     for (int i = 1; i <= V; ++i)
     {
          visited[i] = false;
          inRecursion[i] = false;
     }

     for (int i = 1; i <= V; ++i)
     {
          if (!visited[i] && isCycleDirectedDFS(adj, i, visited, inRecursion))
          {
               return true;
          }
     }

     return false;
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

     bool ans = isCycle(V, adj);
     if (ans)
          cout << "1\n";
     else
          cout << "0\n";

     return 0;
}

/*
For Input:
4 4
0 1
1 2
2 3
3 3

Expected Output:
1
*/