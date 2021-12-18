#include<bits/stdc++.h>
using namespace std;
// count subtree size of every node

vector<vector<int>> adj;
vector<int> subs;

void dfs(int u=1,int p=0){
	for(auto v:adj[u]){
		if(v==p){
			continue;
		}
		dfs(v,u);
		subs[u]+=subs[v];
	}
	subs[u]++;
}

int main(){
	
}