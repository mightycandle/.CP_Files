#include<bits/stdc++.h>
using namespace std;
// lowest common ancestor using binary lifting and timer arrays


class LCA{
	int n,l,timer=0;
	vector<int> tin,tout;
	vector<vector<int>> dp;
	vector<vector<int>> adj;
public:
	LCA(int n,vector<vector<int>> adj){
		this->n=n;
		this->adj=adj;
		lca_init();
	}
	void lca_init(){
		l=ceil(log2(n+1));
		tin.assign(n+1,0);
		tout.assign(n+1,0);
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
		dfs(1,1,dfs);
	}
	bool is_ancestor(int u,int v){
		return tin[u]<=tin[v] and tout[u]>=tout[v];
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
};

int main(){
	
}
