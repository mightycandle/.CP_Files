#include<bits/stdc++.h>
using namespace std;
// edge numbering

int n;
vector<vector<int>> adj;

vector<int> edge_numbering(vector<vector<int>> edges){
	int m=edges.size();
	auto euler_tour=[&]()->vector<int>{
		vector<int> euler;
		vector<bool> vis(n+1);
		auto dfs=[&](int u,int par,auto&& dfs)->void{
			if(vis[u]==1){
				return;
			}
			vis[u]=1;
			euler.push_back(u);
			for(auto v:adj[u]){
				if(v!=par){
					dfs(v,u,dfs);
					euler.push_back(u);
				}
			}
		};
		dfs(1,0,dfs);
		return euler;
	};
	vector<int> euler=euler_tour();
	map<vector<int>,int> convert;
	int cnt=1;
	for(int i=1;i<euler.size()-1;i++){
		vector<int> now={euler[i-1],euler[i]};
		vector<int> nxt={euler[i],euler[i+1]};
		sort(now.begin(),now.end());
		sort(nxt.begin(),nxt.end());
		if(convert[now]==0){
			convert[now]=cnt++;
		}
		if(now!=nxt and convert[nxt]==0){
			convert[nxt]=cnt++;
		}
	}
	vector<int> edge_numbers;
	for(auto e:edges){
		sort(e.begin(),e.end());
		edge_numbers.push_back(convert[e]);
	}
	return edge_numbers;
}

vector<int> euler_tour(){
	
}
int main(){	
	
}