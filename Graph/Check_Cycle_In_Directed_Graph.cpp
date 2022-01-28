#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkCycleDFS(int node, int vis[], int dfsVis[], vector<int> adj[]){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(checkCycleDFS(it, vis, dfsVis, adj)) return true;
            }
            else if(dfsVis[it]) return true;
          
        }
        dfsVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V];
        int dfsVis[V];
        memset(vis, 0, sizeof vis);
        memset(vis, 0, sizeof dfsVis);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(checkCycleDFS(i, vis, dfsVis, adj)) return true;
            }
        }
        return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}