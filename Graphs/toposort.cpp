#include<bits/stdc++.h>
using namespace std;

void dfs(int u){
	vis[u]=1;
	for(auto v:adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	path.push_back(u);
}
void toposort(){
	vis.assign(n+1,0);
	path.clear();
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(path.begin(),path.end());
}

int main(){
	
}
