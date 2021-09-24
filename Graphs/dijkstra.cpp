#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int s){
	vector<int> dist(n,INT_MAX);
	dist[s]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({dist[s],s});
	while(!pq.empty()){
		auto p=pq.top();
		pq.pop();
		for(auto v:adj[p.second]){
			if(dist[v.first]>dist[p.second]+v.second){
				dist[v.first]=dist[p.second]+v.second;
				pq.push({0-dist[v.first],v.first});
			}
		}
	}
	return dist;
}

int main(){
	
}
