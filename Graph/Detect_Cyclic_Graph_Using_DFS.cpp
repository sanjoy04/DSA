#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool cycleDfs(int i, int parent, vector<bool>& vis, vector<int>adj[]){
        vis[i]=true;
        for(auto it : adj[i]){
            if(it==parent) continue;
            if(vis[it]) return true;
            if(cycleDfs(it,i,vis,adj)) return true;
      }
      return false;
  }
  
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(cycleDfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};

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