#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> edges;

vector<int> bellman_ford(){
	int m=edges.size();
	vector<int> dist(n+1,INT_MAX);
	dist[0]=0;
	for(;;){
		int found=0;
		for(auto e:edges){
			int u=e[0],v=e[1],wt=e[2];
			if(dist[u]<INT_MAX and dist[v]>dist[u]+wt){
				dist[v]=dist[u]+wt;
				found=1;
			}
		}
		if(not found){
			break;
		}
	}
	return dist;
}

int main(){

}
