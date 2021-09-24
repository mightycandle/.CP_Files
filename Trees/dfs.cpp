#include<bits/stdc++.h>
using namespace std;

void dfs(int u,int par){
	vis[u]=1;
	for(auto v:adj[u]){
		if(!vis[v] && v!=par){
			dfs(v,u)
		}
	}
}

int main(){
	
}
