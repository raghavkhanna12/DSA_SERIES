#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
     unordered_map<int,list<pair<int,int>>>adj;

     void addedge(int u,int v,int weight){
        pair<int,int>p=make_pair(v,weight);
        adj[u].push_back(p);

     }
    //topological sort
     void dfs(int node,unordered_map<int,bool>&visited,stack<int>&topo){
        visited[node]=true;

        for(auto neighbour:adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,visited,topo);
            }
        }
        topo.push(node);

     }

     void shortestpath(int src,vector<int>&dist,stack<int>&topo){
        dist[src]=0;
        while(!topo.empty()){
            int node=topo.top();
            topo.pop();

            if(dist[node]!=INT_MAX){
                for(auto i:adj[node]){
                   if(dist[node]+i.second<dist[i.first]){
                    dist[i.first]=dist[node]+i.second;
                   }
                }
            }
        }
     }
};

int main(){
    Graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);

    unordered_map<int,bool>visited;
    stack<int>s;
      int n=6;
    for(int i=0;i<n;i++){
    if(!visited[i]){
        g.dfs(i,visited,s);
    }
    }
    vector<int>dist(n);
    int src=1;

    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    g.shortestpath(src,dist,s);

    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;



    
    }