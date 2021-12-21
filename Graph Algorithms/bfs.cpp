#include<bits/stdc++.h>
using namespace std;
// returns distance
int n;
vector<vector<int>> adj;

vector<int> bfs(int s=1){
	vector<int> dist(n+1,INT_MAX);
	vector<bool> vis(n+1);
	queue<int> q;
	q.push(s);
	dist[s]=0;
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