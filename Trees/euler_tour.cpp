#include<bits/stdc++.h>
using namespace std;

void dfs(int u,int par){
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
		path.push_back(u);
	}
}

int main(){
	
}
