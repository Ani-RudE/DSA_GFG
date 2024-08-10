#include <bits/stdc++.h>
using namespace std;

int main() {
     int V, E;
     cin >> V >> E;
     vector<int> adj[V];
     for (int i = 0; i < E; i++)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     return 0;
}

int main() {
     int V;
     cin>>V;
     unordered_map<int, vector<int>> adj;
     for (int i=1; i<=V; ++i) {
          int E;
          cout<<"Num of Edges of Node "<<i<<": ";
          cin>>E;
          cout<<endl;
          int u;
          for (int j=1; j<=E; ++j) {
               cin>>u;
               adj[i].push_back(u);
          }
          cout<<endl;
     }

     return 0;
}