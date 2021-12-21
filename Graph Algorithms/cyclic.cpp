#include<bits/stdc++.h>
using namespace std;
// check for cyclicity and find the cyclic path
int n;
vector<vector<int>> adj;

vector<int> cyclic(){
	int cys=-1,cye=-1;
	vector<int> color(n+1),parent(n+1);
	auto dfs=[&](int u,auto&& dfs)->bool{
		color[u]=1;
		for(auto v:adj[u]){
			if(color[v]==0){
				parent[v]=u;
				if(dfs(v,dfs)){
					return 1;
				}
			}
			else if(color[v]==1){
				cys=v,cye=u;
				return 1;
			}
		}
		color[u]=2;
		return 0;
	};
	for(int i=1;i<=n;i++){
		if(color[i]==0 && dfs(i,dfs)){
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