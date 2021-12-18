#include<bits/stdc++.h>
using namespace std;
// returns 1 if bipartite coloring is possible
int n;
vector<vector<int>> adj;

bool is_bipartite(int s=1){
	vector<int> color(n+1,-1);
	queue<int> q;
	q.push(s);
	color[s]=1;
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		for(auto v:adj[u]){
			if(color[v]==-1){
				color[v]=color[u]^1;
				q.push(v);
			}
			else if(color[u]==color[v]){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	
}