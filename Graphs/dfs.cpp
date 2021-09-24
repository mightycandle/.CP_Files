#include<bits/stdc++.h>
using namespace std;

void dfs(int u){
	vis[u]=1;
	for(auto v:adj[u]){
		if(vis[v]==0){
			dfs(v);
		}
	}
}

int main(){
	
}
