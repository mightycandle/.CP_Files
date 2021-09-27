#include<bits/stdc++.h>
using namespace std;
vector<int> euler;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int u,int par=-1){
	if(vis[u]==1){
		return;
	}
	vis[u]=1;
	euler.push_back(u);
	for(auto v:adj[u]){
		if(v==par){
			continue;
		}
		dfs(v,u);
		euler.push_back(u);
	}
}

int main(){
	
}