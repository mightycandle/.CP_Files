#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
// distance = d(u) + d(v) - 2*d(lca(u,v))
// check if ancestor using t-in and t-out timer arrays

vector<vector<int>> dp;
vector<int> tin,tout;
vector<int> dist;
int n,l,timer=0;
void dfs(int u,int par){
	tin[u]=++timer;
	dp[u][0]=par;
	for(int i=1;i<=l;i++){
		dp[u][i]=dp[dp[u][i-1]][i-1];
	}
	for(auto v:adj[u]){
		if(v^par){
			dist[v]=dist[u]+1;
			dfs(v,u);
		}
	}
	tout[u]=++timer;
}
bool is_ancestor(int u,int v){
	return tin[u]<=tin[v] && tout[u]>=tout[v];
}
int lca(int u,int v){
	if(is_ancestor(u,v)){
		return u;
	}
	if(is_ancestor(v,u)){
		return v;
	}
	for(int i=l;i>=0;i--){
		if(!is_ancestor(dp[u][i],v)){
			u=dp[u][i];
		}
	}
	return dp[u][0];
}
int distance(int x,int y){
	int z=lca(x,y);
	return abs(dist[x]+dist[y]-(dist[z]<<1));
}

int main(){
	
}