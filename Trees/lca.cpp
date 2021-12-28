#include<bits/stdc++.h>
using namespace std;
// lowest common ancestor using binary lifting and timer arrays
vector<vector<int>> adj;

vector<vector<int>> dp;
vector<int> tin,tout;
int n,l,timer=0;
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
	tin.resize(n+1);
	tout.resize(n+1);
	timer=0;
	l=ceil(log2(n+1));
	dp.assign(n+1,vector<int>(l+1));
	auto dfs=[&](int u,int par,auto&& dfs)->void{
		tin[u]=++timer;
		dp[u][0]=par;
		for(int i=1;i<=l;i++){
			dp[u][i]=dp[dp[u][i-1]][i-1];
		}
		for(auto v:adj[u]){
			if(v^par){
				dfs(v,u,dfs);
			}
		}
		tout[u]=++timer;
	};
	dfs(root,root,dfs);
}

int main(){
	
}