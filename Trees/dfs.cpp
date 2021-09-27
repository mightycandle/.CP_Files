#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int u,int par=-1){
	vis[u]=1;
	for(auto v:adj[u]){
		if(!vis[v] && v!=par){
			dfs(v,u);
		}
	}
}

int main(){
	
}