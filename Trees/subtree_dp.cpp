#include<bits/stdc++.h>
using namespace std;
// count subtree size of every node

int n;
vector<vector<int>> adj;

vector<int> get_subtree(){
	vector<int> dp(n+1);
	auto dfs=[&](int u,int par,auto&& dfs)->void{
		for(auto v:adj[u]){
			if(v==par){
				continue;
			}
			dfs(v,u,dfs);
			dp[u]+=dp[v];
		}
		dp[u]++;
	};
	dfs(1,0,dfs);
	return dp;
}

int main(){
	
}
