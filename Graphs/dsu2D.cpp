#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> parent,depth;
void make_set(int u,int id){
	if(parent[id][u]==0){
		parent[id][u]=u;
		depth[id][u]=1;
	}
}
int find_set(int u,int id){
	if(parent[id][u]==u){
		return u;
	}
	return parent[id][u]=find_set(parent[id][u],id);
}
void union_set(int u,int v,int id){
	u=find_set(u,id),v=find_set(v,id);
	if(u!=v){
		if(depth[id][u]<depth[id][v]){
			swap(u,v);
		}
		parent[id][v]=u;
		depth[id][u]+=depth[id][v];
	}
}
void init_dsu(int n,int m){
	parent.assign(m+1,vector<int>(n+1));
	depth.assign(m+1,vector<int>(n+1));
	for(int j=0;j<=m;j++){
		for(int i=1;i<=n;i++){
			make_set(j,i);
		}
	}
}

int main(){
	
}