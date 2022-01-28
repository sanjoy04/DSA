#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void topoSortDFS(int node, stack<int> &st, int vis[], vector<int> adj[]){
	    vis[node] = true;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            topoSortDFS(it, st, vis, adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    int vis[V];
	    memset(vis, 0, sizeof vis);
	    for(int i=0; i<V; i++){
	        if(!vis[i])
	            topoSortDFS(i, st, vis, adj);
	    }
	    vector<int> topo;
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}