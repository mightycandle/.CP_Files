#include<bits/stdc++.h>
using namespace std;
int n;

class Edge{ public:
	int x,y,wt;
	bool operator < (Edge const& e){
		return wt < e.wt;
	}
	void read(){
		cin >> x >> y >> wt;
	}
};
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
void kruskal(vector<Edge> edges){
	parent.resize(n+1);
	ranks.resize(n+1);
	for(int i=1;i<=n;i++){
		make_set(i);
	}
	int cost=0;
	vector<Edge> res;
	sort(edges.begin(),edges.end());
	for(auto e:edges){
		if(find_set(e.x)!=find_set(e.y)){
			res.push_back(e);
			cost+=e.wt;
			union_set(e.x,e.y);
		}
	}
}


int main(){
	
}