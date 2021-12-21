#include<bits/stdc++.h>
using namespace std;
// returns vector of the root (from dsu) of the connected component
int n;
vector<vector<int>> edges;

vector<int> connected_components(){
	vector<int> parent(n+1),depth(n+1);
	auto make_set=[&](int u)->int{
		if(parent[u]==0){
			parent[u]=u;
			depth[u]=1;
		}
	};
	auto find_set=[&](int u,auto &&find_set)->int{
		return parent[u]==u?u:parent[u]=find_set(parent[u],find_set);
	};
	auto union_set=[&](int u,int v)->void{
		u=find_set(u,find_set),v=find_set(v,find_set);
		if(u!=v){
			if(depth[u]<depth[v]){
				swap(u,v);
			}
			parent[v]=u;
			depth[u]+=depth[v];
		}
	};
	for(int i=1;i<=n;i++){
		make_set(i);
	}
	for(auto e:edges){
		int u=find_set(e[0],find_set);
		int v=find_set(e[1],find_set);
		if(u!=v){
			union_set(u,v);
		}
	}
	return parent;
}

int main(){
	
}