#include<bits/stdc++.h>
using namespace std;
// returns vector of the root (from dsu) of the connected component

int n;
vector<vector<int>> edges;

vector<int> parent,depth;
void make_set(int u){
	if(parent[u]==0){
		parent[u]=u;
		depth[u]=1;
	}
}
int find_set(int u){
	return parent[u]==u?u:parent[u]=find_set(parent[u]);
}
void union_set(int u,int v){
	u=find_set(u),v=find_set(v);
	if(u!=v){
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		parent[v]=u;
		depth[u]+=depth[v];
	}
}
vector<int> connected_components(){
	parent.assign(n+1,0);
	depth.assign(n+1,0);
	for(int i=1;i<=n;i++){
		make_set(i);
	}
	for(auto e:edges){
		int u=find_set(e[0]);
		int v=find_set(e[1]);
		if(u==v){
			continue;
		}
		union_set(u,v);
	}
	return parent;
}

int main(){
	
}