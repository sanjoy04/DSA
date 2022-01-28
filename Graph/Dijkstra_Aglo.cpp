#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>distt(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        distt[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(auto it:adj[prev]){
                int next = it[0];
                int nextDist = it[1];
                if(distt[next]>distt[prev]+nextDist){
                    distt[next] = distt[prev]+nextDist;
                    pq.push({distt[next],next});
                }
            }
        }
        return distt;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}