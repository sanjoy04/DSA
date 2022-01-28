#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void shortestPath(int src,int N, vector<int>adj[]){
            queue<int>q;
            vector<int>dist(N, INT_MAX);

            q.push(src);
            dist[src]=0;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    if(dist[node]+1 < dist[it]){
                        dist[it] = dist[node]+1;
                        q.push(it);
                    }
                }
            }
            for(int i=0; i<N; i++){
                cout<<dist[i]<<" ";
            }
        }
};
int main() {
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0; i<e; i++){
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    Solution obj;
    obj.shortestPath(0, n, adj);
}