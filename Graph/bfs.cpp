#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void bfs(int s);
};

Graph::Graph(int vertices){
    V = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bfs(int s){
    bool *visited = new bool[V];
    for(int i=0; i<V; i++){
        visited[i]=false;
    }

    queue<int>q;
    visited[s]=true;
    q.push(s);
    list<int>::iterator i;
    while(!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
    return 0;
}
