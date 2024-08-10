#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

bool isCycleBFS(unordered_map<int, vector<int>> &adj, int u, unordered_map<int, bool> &visited)
{
     queue<pair<int, int>> q;
     q.push({u, -1});
     visited[u] = true;

     while (!q.empty())
     {
          int source = q.front().first;
          int parent = q.front().second;
          q.pop();

          for (auto &x : adj[source])
          {
               if (!visited[x])
               {
                    visited[x] = true;
                    q.push({x, source});
               }
               else if (x != parent)
               {
                    return true;
               }
          }
     }

     return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, unordered_map<int, vector<int>> &adj)
{
     unordered_map<int, bool> visited;
     for (int i = 0; i < V; ++i)
     {
          if (!visited[i] && isCycleBFS(adj, i, visited))
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

/* ALTERNATE WAY TO WRITE THE Adjacency Matrix
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    bool isCycleBFS(vector<int> adj[], int u, vector<bool> &visited) {
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;

        while (!q.empty()) {
            int source = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto &x: adj[source]) {
                if (visited[x]==false) {
                    visited[x] = true;
                    q.push({x, source});
                } else if (x!=parent) {
                    return true;
                }
            }
        }

        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for (int i=0; i<V; ++i) {
            if (!visited[i] && isCycleBFS(adj, i, visited)) {
                return true;
            }
        }

        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
*/