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
    bool cyclebfs(unordered_map<int,bool>&visited, vector<int>*adj, int src) {
    queue<int> q;
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        for (auto neighbour : adj[frontNode]) {
            if (visited[neighbour] && neighbour != parent[frontNode]) {
                return true;
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}
bool cycledfs(unordered_map<int,bool>&visited,vector<int>* adj,int node,int parent){
    visited[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool ans= cycledfs(visited,adj,neighbour,node);
            if(ans){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
    
}
 // Function to detect cycle in a directed graph.
    bool cycledfs(unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,vector<int>*adj,int node){
        visited[node]=true;
        dfsvisited[node]=true;
        
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                bool ans=cycledfs(visited,dfsvisited,adj,neighbour);
                if(ans==1){
                    return true;
                }
            }
            else if(dfsvisited[neighbour]){
                return true;
            }
        }
        dfsvisited[node]=false;
        return false;


    }
    void toposortdfs(unordered_map<int,bool>&visited,stack<int>&s,vector<int>*adj,int node){
	    visited[node]=true;
	    
	    for(auto neighbour:adj[node]){
	        if(!visited[neighbour]){
	            toposortdfs(visited,s,adj,neighbour);
	        }
	    }
	    s.push(node);
	}
	
	//common to all the function a little changes is required
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int,bool>visited;
	    stack<int>s;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            toposortdfs(visited,s,adj,i);
	        }
	    }
	    
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s,int t) {
              
	unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
		adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;

    queue<int>q;
    q.push(s);
	parent[s]=-1;
    visited[s]=true;
    
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        visited[frontNode]=true;

        for( auto i:adj[frontNode]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=frontNode;
			q.push(i);
            }
        }

    }

    vector<int>ans;

    int current=t;
	ans.push_back(t);
    while(current!=s){
        current=parent[current];
        ans.push_back(current);
    }
    reverse(ans.begin(),ans.end());
    return ans;

	}
    
//Dijkstra Algorithm
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
 
  unordered_map<int,list<pair<int,int>>>adj;

  for(int i=0;i<edges;i++){
  int u=vec[i][0];
  int v=vec[i][1];
  int w=vec[i][2];
  adj[u].push_back(make_pair(v,w));
  adj[v].push_back(make_pair(u,w));
 }

 vector<int>dist(vertices);
 for(int i=0;i<vertices;i++){
    dist[i]=INT_MAX;
 }

 set<pair<int,int>>st;
 dist[source]=0;
 st.insert(make_pair(0,source));

 while(!st.empty()){
    auto top = *(st.begin());

    int nodeDistance=top.first;
    int node=top.second;

    st.erase(st.begin());

    for(auto neighbour:adj[node]){
        if(nodeDistance+neighbour.second<dist[neighbour.first]){
            auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));

            if(record!=st.end()){
                st.erase(record);
            }
        
        dist[neighbour.first]=nodeDistance+neighbour.second;
        st.insert(make_pair(dist[neighbour.first],neighbour.first));

        }
    }
 }
return dist;

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