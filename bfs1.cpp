#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    map<int,list<int>>adj;
    void addedge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==false){
            adj[v].push_back(u);
        }
    }

    void bfs(int node){
        queue<int>q;
        map<int,bool>visited;
        vector<int>ans;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }

        for(auto i:ans){
            cout<<i<<" ";
        }


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

};

int main(){
    Graph g;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g.addedge(u,v,false);
}
g.print();
g.bfs(0);
}