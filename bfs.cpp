#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int,list<int>> adj;
    unordered_map<int,bool>vis;
    
    void addedge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u); // If direction is false, add edge from v to u as well
        }
    }

    void bfs(int node){
        unordered_map<int,bool> visited;
        vector<int> ans;
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        // Print BFS traversal
        cout << "BFS Traversal: ";
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }

    void print(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " , ";
            }
            cout << endl;
        }
    }

    void dfs(int node){
        vector<int>v;
        cout<<node<<" ";
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i);
            }
        }
    }

};

int main(){
    int n, m;
    cin >> n >> m;
    Graph g;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, false); // Assuming undirected graph, so direction is false
    }
    g.print(); // Print adjacency list
    g.bfs(0); // Perform BFS starting from node 0
    g.dfs(0);
    return 0;
}
