#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

vector<int> euler_tour(){
	vector<int> euler;
	vector<bool> vis(n+1);
	auto dfs=[&](int u,int par,auto&& dfs)->void{
		if(vis[u]==1){
			return;
		}
		vis[u]=1;
		euler.push_back(u);
		for(auto v:adj[u]){
			if(v!=par){
				dfs(v,u,dfs);
				euler.push_back(u);
			}
		}
	};
	dfs(1,0,dfs);
	return euler;
}

int main(){
	
}