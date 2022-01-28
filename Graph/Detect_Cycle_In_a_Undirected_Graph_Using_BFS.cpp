#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkForCycle(int node,vector<int>&visited,vector<int> adj[])
   {
       queue<pair<int,int>>q;
       q.push({node,-1});
       visited[node]=true;
       while(!q.empty())
       {
           int node=q.front().first;
           int par=q.front().second;
           q.pop();
           for(auto it:adj[node])
           {
               if(!visited[it])
               {
                   q.push({it,node});
                   visited[it]=true;
               }
               else if(it!=par)
               {
                       return true;   
               }
           }
       
       }
       return false;
   }
   bool isCycle(int v, vector<int> adj[]) {
       vector<int>visited(v,0);
       for(int i=0;i<v;i++)
       {
           if(!visited[i])
           {
               if(checkForCycle(i,visited,adj))
               {
                   return true;
               }
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