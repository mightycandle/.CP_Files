#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> dist;

void dfs(int u,int par=0){
	vis[u]=1;
	for(auto v:adj[u]){
		if(vis[v] or v==par){
			continue;
		}
		dist[v]=dist[u]+1;
		dfs(v,u);
	}
}
int get_diameter(){
	int n=adj.size();
	dist.assign(n,0);
	vis.assign(n,0);
	dfs(1);
	int root=max_element(dist.begin(),dist.end())-dist.begin();
	dist.assign(n,0);
	vis.assign(n,0);
	dfs(root);
	return *max_element(dist.begin(),dist.end());
}

int main(){
	
}