#include<bits/stdc++.h>
using namespace std;
// check for cyclicity and find the cyclic path
int n;
vector<vector<int>> adj;

vector<int> cyclic(){
	int cys=-1,cye=-1;
	vector<int> vis(n+1),parent(n+1);
	auto dfs=[&](int u,auto&& dfs)->bool{
		vis[u]=1;
		for(auto v:adj[u]){
			if(vis[v]==0){
				parent[v]=u;
				if(dfs(v,dfs)){
					return 1;
				}
			}
			else if(vis[v]==1){
				cys=v,cye=u;
				return 1;
			}
		}
		vis[u]=2;
		return 0;
	};
	for(int i=1;i<=n;i++){
		if(vis[i]==0 && dfs(i,dfs)){
			break;
		}
	}
	// return (cys!=-1);
	if(cys==-1){
		return {-1};
	}
	vector<int> path={cys};
	for(int i=cye;i!=parent[cys];i=parent[i]){
		path.push_back(i);
	}
	reverse(path.begin(),path.end());
	// {start,......,end,start}
	return path;
}

int main(){
	
}