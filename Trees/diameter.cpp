#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;

int get_diameter(){
	vector<int> dist(n+1),vis(n+1);
	auto dfs=[&](int u,int par,auto&& dfs)->void{
		vis[u]=1;
		for(auto v:adj[u]){
			if(vis[v] or v==par){
				continue;
			}
			dist[v]=dist[u]+1;
			dfs(v,u,dfs);
		}
	};
	dfs(1,0,dfs);
	int root=max_element(dist.begin(),dist.end())-dist.begin();
	dist.assign(n,0);
	vis.assign(n,0);
	dfs(root,0,dfs);
	return *max_element(dist.begin(),dist.end());
}

int main(){
	
}