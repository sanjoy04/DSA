#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int, bool> visited;
    map<int, list<int> > adj;
    public:
    void addEdge(int v, int w);
    void dfs(int v);
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::dfs(int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
     for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                dfs(*i);
            }
        }
}

int main(){
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 9);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.dfs(1);
    return 0;
}
