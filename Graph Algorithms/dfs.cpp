#include<bits/stdc++.h>
using namespace std;
// just a dfs traversal
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int u){
	vis[u]=1;
	for(auto v:adj[u]){
		if(not vis[v]){
			dfs(v);
		}
	}
}

int main(){	
	auto dfs=[&](int u,auto&& dfs)->void{
		vis[u]=1;
		for(auto v:adj[u]){
			if(not vis[v]){
				dfs(v,dfs);
			}
		}
	};
}