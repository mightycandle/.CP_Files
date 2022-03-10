#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;

vector<int> toposort(){
	vector<bool> vis(n+1);
	vector<int> path;
	auto dfs=[&](int u,auto&& dfs)->void{
		vis[u]=1;
		for(auto v:adj[u]){
			if(vis[v]==0){
				dfs(v,dfs);
			}
		}
		path.push_back(u);
	};
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		dfs(i,dfs);
	}
	reverse(path.begin(),path.end());
	return path;
}

int main(){
	
}