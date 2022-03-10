#include<bits/stdc++.h>
using namespace std;
// returns the number of connected components
int n;
vector<vector<int>> adj;

int count_connected_comps(){
	vector<bool> vis(n+1);
	int cnt=0;
	auto dfs=[&](int u,auto &&dfs)->void{
		vis[u]=1;
		for(auto v:adj[u]){
			if(vis[v]==0){
				dfs(v,dfs);
			}
		}
	};
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		cnt++;
		dfs(i,dfs);
	}
	return cnt;
}

int main(){
	
}