#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, int vis[], stack<int>&st, vector<pair<int,int>>adj[]){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            topoSort(it.first,vis,st,adj);
        }
    }
    st.push(node);
}
void shortestPath(int src, int N, vector<pair<int,int>>adj[]){
    int vis[N]={0};
    stack<int>st;
    for(int i=0; i<N; i++){
        if(!vis[i]){
            topoSort(i,vis,st,adj);
        }
    }

    int dist[N];
    for (int i = 0; i < N; i++) 
		dist[i] = INT_MAX;
    dist[src]=0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it:adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        (dist[i]==INT_MAX)? cout<<"INF":cout<<dist[i]<<" ";
    }
}
int main() {
    int N, E;
    cin>>N>>E;
    vector<pair<int,int>>adj[N];
    for(int i=0; i<E; i++){
        int s,d,wt;
        cin>>s>>d>>wt;
        adj[s].push_back({d,wt});
    }
    shortestPath(0, N, adj);
}
