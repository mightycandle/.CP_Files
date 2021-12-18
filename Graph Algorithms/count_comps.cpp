#include<bits/stdc++.h>
using namespace std;
// returns the number of connected components
int n;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u){
	vis[u]=1;
	for(auto v:adj[u]){
		dfs(v);
	}
}

int count_connected_comps(){
	vis.assign(n+1,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}

int main(){
	
}