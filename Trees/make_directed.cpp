#include<bits/stdc++.h>
using namespace std;
// pre-req: distances array from root
// dist is the distance array from bfs()

int n;
vector<vector<int>> adj;
vector<vector<int>> edges;

void make_directed(vector<int> dist){
	adj.assign(n+1,vector<int>());
	for(auto e:edges){
		int u=e[0],v=e[1];
		if(dist[u]>dist[v]){
			swap(u,v);
		}
		adj[u].push_back(v);
	}
}

int main(){
	
}