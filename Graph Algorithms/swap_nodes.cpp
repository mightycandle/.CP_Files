#include<bits/stdc++.h>
using namespace std;
// swap nodes
int n;
vector<vector<int>> adj;
vector<vector<int>> edges;
vector<int> deg;

void swap_nodes(int u,int v){
	for(auto &e:edges){
		for(auto &x:e){
			if(x==u){
				x=v;
			}
			else if(x==v){
				x=u;
			}
		}
	}
	adj.assign(n+1,vector<int>());
	for(auto e:edges){
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	// deg.assign(n+1,0);
	// for(auto e:edges){
	// 	deg[e[0]]++;
	// 	deg[e[1]]++;
	// }
}

int main(){
	
}