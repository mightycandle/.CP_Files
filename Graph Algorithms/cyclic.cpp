#include<bits/stdc++.h>
using namespace std;
// check for cyclicity and find its start and end nodes
int n;
vector<vector<int>> adj;

int cys=-1,cye=-1;
vector<int> color,parent;
bool Dfs(int u){
	color[u]=1;
	for(auto v:adj[u]){
		if(color[v]==0){
			parent[v]=u;
			if(Dfs(v)){
				return true;
			}
		}
		else if(color[v]==1){
			cys=v,cye=u;
			return true;
		}
	}
	color[u]=2;
	return false;
}
bool cyclic(){
	color.resize(n+1);
	parent.resize(n+1);
	for(int i=1;i<=n;i++){
		if(color[i]==0 && Dfs(i))
			break;
	}
	return cys!=-1;
}

int main(){
	
}