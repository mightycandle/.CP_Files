#include<bits/stdc++.h>
using namespace std;
int n;
vector<bool> vis;
vector<vector<int>> adj;


vector<int> bfs(int s){
	vector<int> dist(n+1,INT_MAX);
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		vis[u]=1;
		for(auto v:adj[u]){
			if(vis[v]==0){
				q.push(v);
				dist[v]=dist[u]+1;
			}
		}
	}
	return dist;
}

int main(){
	
}