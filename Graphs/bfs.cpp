#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int s){
	vector<int> dist(n,INT_MAX);
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		vis[u]=1;
		for(auto v:u){
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