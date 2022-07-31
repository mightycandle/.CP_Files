#include "bits/stdc++.h"
using namespace std;
// need LCA to implement

class LCA{
	int n,l,timer=0;
	vector<int> tin,tout;
	vector<vector<int>> dp;
	vector<vector<int>> adj;
public:
	LCA(){}
	LCA(int n,vector<vector<int>> adj){
		this->n=n;
		this->adj=adj;
		lca_init();
	}
	void lca_init(){
		l=ceil(log2(n+1));
		tin.assign(n+1,0);
		tout.assign(n+1,0);
		dp.assign(n+1,vector<int>(l+1));
		auto dfs=[&](int u,int par,auto&& dfs)->void{
			tin[u]=++timer;
			dp[u][0]=par;
			for(int i=1;i<=l;i++){
				dp[u][i]=dp[dp[u][i-1]][i-1];
			}
			for(auto v:adj[u]){
				if(v^par){
					dfs(v,u,dfs);
				}
			}
			tout[u]=++timer;
		};
		dfs(1,1,dfs);
	}
	bool is_ancestor(int u,int v){
		return tin[u]<=tin[v] and tout[u]>=tout[v];
	}
	int lca(int u,int v){
		if(is_ancestor(u,v)){
			return u;
		}
		if(is_ancestor(v,u)){
			return v;
		}
		for(int i=l;i>=0;i--){
			if(!is_ancestor(dp[u][i],v)){
				u=dp[u][i];
			}
		}
		return dp[u][0];
	}
};

class HLD{ public:
	int n;
	vector<int> a,t;
	vector<vector<int>> adj,chains;
	vector<int> parent,heavyChild,chainHead;
	vector<int> subs,index,linear;
	LCA L;
	HLD(vector<int> _a,vector<vector<int>> _adj){
		n=_adj.size()-1;
		while(n&(n-1)){
			n++;
		}
		a=_a;
		adj=_adj;
		a.resize(n);
		adj.resize(n+1);
		L=LCA(n,adj);
		MakeChain();
		build();
	}
	void merge(int i){
		t[i]=t[i<<1]+t[i<<1|1];
	}
	void build(){
		index.assign(n+1,0);
		for(int i=0;i<n;i++){
			index[linear[i]]=i;
		}
		vector<int> tmp(n);
		for(int i=0;i<n;i++){
			tmp[i]=a[linear[i]-1];
		}
		a=tmp;
		t.assign(n<<1,0);
		for(int i=n;i<(n<<1);i++){
			t[i]=a[i-n];
		}
		for(int i=n-1;i>=1;i--){
			merge(i);
		}
	}
	void make_subtree(){
		subs.assign(n+1,0);
		auto dfs=[&](int u,int par,auto&& dfs)->void{
			for(auto v:adj[u]){
				if(v==par){
					continue;
				}
				dfs(v,u,dfs);
				subs[u]+=subs[v];
			}
			subs[u]++;
		};
		dfs(1,0,dfs);
	}
	void MakeChain(){
		make_subtree();
		auto adjSort=[&](int u,int v)->bool{
			return subs[u]>subs[v];
		};
		for(int i=1;i<=n;i++){
			sort(adj[i].begin(),adj[i].end(),adjSort);
		}
		parent.assign(n+1,0);
		heavyChild.assign(n+1,0);
		for(int u=1;u<=n;u++){
			for(auto v:adj[u]){
				if(subs[v]>subs[u]){
					parent[u]=v;
					continue;
				}
				parent[v]=u;
				if(subs[v]>=(subs[u]/2)){
					heavyChild[u]=v;
				}
			}
		}
		chains.assign(n+1,vector<int>());
		for(int i=1;i<=n;i++){
			chains[i].push_back(i);
		}
		vector<bool> vis(n+1);
		chainHead.assign(n+1,0);
		for(int i=1;i<=n;i++){
			chainHead[i]=i;
		}
		auto find_head=[&](int u,auto&& find_head)->int{
			if(chainHead[u]==u){
				return u;
			}
			return chainHead[u]=find_head(chainHead[u],find_head);
		};
		auto dfs=[&](int u,int par,auto&& dfs)->void{
			vis[u]=1;
			for(auto v:adj[u]){
				if(vis[v] or v==par){
					continue;
				}
				if(heavyChild[u]==v){
					int curHead=find_head(u,find_head);
					chains[curHead].push_back(v);
					chainHead[v]=curHead;
				}
				dfs(v,u,dfs);
			}
		};
		dfs(1,0,dfs);
		auto lenSort=[&](vector<int> u,vector<int> v)->bool{
			if(u.size()==v.size()){
				if(u.size()==1){
					return adj[u[0]].size()>adj[v[0]].size();
				}
			}
			return u.size()>v.size();
		};
		sort(chains.begin(),chains.end(),lenSort);
		linear.clear();
		vis.assign(n+1,0);
		for(auto y:chains){
			for(auto x:y){
				if(vis[x]){
					continue;
				}
				linear.push_back(x);
				vis[x]=1;
			}
		}
	}
	void update(int node,int val){
		int idx=index[node];
		a[idx]=val;
		t[idx+=n]=val;
		for(int i=idx/2;i>=1;i/=2){
			merge(i);
		}
	}
	int segQuery(int v,int tl,int tr,int l,int r){
		if(r<tl or tr<l or tr<tl){
			return 0;
		}
		if(l<=tl and tr<=r){
			return t[v];
		}
		int tm=(tl+tr)/2;
		int left=segQuery(v<<1,tl,tm,l,r);
		int right=segQuery(v<<1|1,tm+1,tr,l,r);
		return left+right;
	}
	int query(int u,int v){
		int ans=0;
		auto subQuery=[&](int x,int y)->int{
			int z=L.lca(x,y);
			if(u==v){
				return a[index[u]];
			}
			if(subs[u]>subs[v]){
				swap(u,v);
			}
			for(int i=index[u];i!=index[v];){
				if(chainHead[linear[i]]==linear[i]){
					ans+=a[index[linear[i]]];
					i=index[parent[linear[i]]];
					if(i==index[v]){
						ans+=a[index[v]];
					}
				}
				else{
					int head=chainHead[linear[i]];
					if(chainHead[v]==head){
						head=v;
					}
					int res=segQuery(1,0,n-1,index[head],i);
					ans+=res;
					if(v==head){
						i=index[head];
					}
					else{
						i=index[parent[head]];
						if(i==index[v]){
							ans+=a[index[v]];
						}
					}
				}
			}
			return ans;
		};
		return qu(x,z)+qu(z,y)-a[index[z]];
	}
};
