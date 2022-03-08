#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edges;
vector<int> parent,ranks;

void make_set(int u){
	parent[u]=u;
}
int find_set(int u){
	if(u==parent[u]){
		return u;
	}
	return parent[u]=find_set(parent[u]);
}
void union_set(int u,int v){
	u=find_set(u),v=find_set(v);
	if(u!=v){
		if(ranks[u]<ranks[v]){
			swap(u,v);
		}
		parent[v]=u;
		if(ranks[u]==ranks[v]){
			ranks[u]++;
		}
	}
}
void kruskal(vector<vector<int>> edges){
	parent.resize(n+1);
	ranks.resize(n+1);
	for(int i=1;i<=n;i++){
		make_set(i);
	}
	int cost=0;
	vector<vector<int>> res;
	auto cmp=[&](vector<int> a,vector<int> b)->bool{
		return a[2]<b[2];
	};
	sort(edges.begin(),edges.end(),cmp);
	for(auto e:edges){
		int u=e[0],v=e[1],w=e[2];
		if(find_set(u)!=find_set(v)){
			res.push_back(e);
			cost+=w;
			union_set(u,v);
		}	
	}
}


int main(){
	
}