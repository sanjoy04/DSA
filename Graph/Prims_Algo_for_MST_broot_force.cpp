#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        int mst[V];
        int parent[V];
        for(int i=0; i<V; i++){
            key[i]=INT_MAX, mst[i]=false, parent[V]=-1;
        }
        
        key[0]=0;
        parent[0]=-1;
        
        for(int count=0; count<V-1; count++){
            int mini = INT_MAX,u;
            for(int v=0; v<V; v++){
                if(mst[v]==false && key[v]<mini){
                    mini = key[v];
                    u=v;
                }
            }
            mst[u]=true;
            
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(mst[v]==false && weight<key[v]){
                    parent[v]=u;
                    key[v]=weight;
                }
            }
        }
        int res=0;
        for(int i=0; i<V; i++){
            res += key[i];
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}