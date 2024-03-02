#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    map<int,list<int>>adj;
    void addedge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(v);
        }

    }
       void bfs(unordered_map<int,bool>&visited,vector<int>&ans,vector<int>*adj,int node){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            visited[frontNode]=1;
            ans.push_back(frontNode);
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
    void dfs(unordered_map<int,bool>&visited,vector<int>&ans,vector<int>*adj,int node){
        ans.push_back(node);
        visited[node]=true;
        
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(visited,ans,adj,i);
            }
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    Graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    g.print();
}