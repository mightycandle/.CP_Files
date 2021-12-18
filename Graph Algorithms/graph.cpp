#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	int n;
	vector<int> dx={0,-1,0,1,-1,-1,1,1};
	vector<int> dy={1,0,-1,0,1,-1,-1,1};
	vector<int> parent,depth,deg;
	vector<bool> vis;
	vector<vector<int>> adj,edges;
public:
	Graph(int is_tree=0,int m=-1){
		cin>>n;
		if(!is_tree){
			cin>>m;
		}
		else m=n-1;
		adj.assign(n+1,vector<int>());
		edges.assign(m,vector<int>(2));
		deg.assign(n+1,0);
		vis.assign(n+1,0);
		depth.assign(n+1,0);
		parent.assign(n+1,0);
		for(int i=1;i<=n;i++){
			parent[i]=i,depth[i]=1;
		}
	}
	void allot(int nn,vector<vector<int>> edge,int dir=0){
		n=nn;
		edges=edge;
		for(auto v:edges){
			adj[v[0]].push_back(v[1]);
			if(dir==0){
				adj[v[1]].push_back(v[0]);
			}
		}
	}
	void input(int dir=0){
		for(auto &uv:edges){
			cin>>uv[0]>>uv[1];
			adj[uv[0]].push_back(uv[1]);
			deg[uv[0]]++;
			if(!dir){
				adj[uv[1]].push_back(uv[0]);
				deg[uv[1]]++;
			}
		}
	}
	void write(){
		for(int i=0;i<=n;i++){
			cout << i << ": ";
			for(auto x:adj[i]){
				cout << x << ' ';
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
	int find_set(int u){
		if(parent[u]==u){
			return u;
		}
		return parent[u]=find_set(parent[u]);
	}
	void union_set(int u,int v){
		u=find_set(u),v=find_set(v);
		if(u!=v){
			if(depth[u]<depth[v]){
				swap(u,v);
			}
			parent[v]=u;
			depth[u]+=depth[v];
		}
	}
	void dsu(){
		for(auto uv:edges){
			union_set(uv[0],uv[1]);
		}
	}
	vector<int> bfs(int s){
		vector<int> dist(n+1,INT_MAX);
		dist[s]=0;
		queue<int> q;q.push(s);
		while(!q.empty()){
			auto u=q.front();q.pop();
			for(auto v:adj[u]){
				if(dist[v]>dist[u]+1){
					dist[v]=dist[u]+1;
					q.push(v);
				}
			}
		}
		return dist;
	}
	void dfs(int u){
		vis[u]=1;
		for(auto v:adj[u]){
			if(vis[v]==0){
				dfs(v);
			}
		}
	}
	void solve(){
		
	}
};

int main(){
	
}