#include<bits/stdc++.h>
using namespace std;

vector<int> parent,depth;
void make_set(int u){
	if(parent[u]==0){
		parent[u]=u;
		depth[u]=1;
	}
}
int find_set(int u){
	if(parent[u]==u){
		return u;
	}
	return parent[u]=find_set(parent[u]);
}
void refresh(){
	for(int i=1;i<parent.size();i++){
		parent[i]=find_set(parent[i]);
	}
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
void init_dsu(int n){
	parent.assign(n+1,0);
	depth.assign(n+1,0);
	for(int i=1;i<=n;i++){
		make_set(i);
	}
}

int main(){
	
}