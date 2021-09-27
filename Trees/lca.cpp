#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

vector<vector<int>> dp;
vector<int> tin,tout;
int n,l,timer=0;
void dfs(int u,int par){
	tin[u]=++timer;
	dp[u][0]=par;
	for(int i=1;i<=l;i++){
		dp[u][i]=dp[dp[u][i-1]][i-1];
	}
	for(auto v:adj[u]){
		if(v^par){
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
void lca_init(int root=1){
	tin.resize(n);
	tout.resize(n);
	timer=0;
	l=ceil(log2(n));
	dp.assign(n,vector<int>(l+1));
	dfs(root,root);
}

int main(){
	
}