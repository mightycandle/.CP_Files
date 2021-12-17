#include<bits/stdc++.h>
using namespace std;
// dynamic range sum queries

int n;
vector<int> a;
vector<int> t;
void merge(int i){
	t[i]=t[i<<1]+t[i<<1|1];
}
void build(){
	while(n&(n-1)){
		++n;
		a.push_back(0);
	}
	t.assign(n<<1,0);
	for(int i=0;i<n;i++){
		t[i+n]=a[i];
	}
	for(int i=n-1;i>=1;i--){
		merge(i);
	}
}
int query(int v,int tl,int tr,int l,int r){
	if(tr<l || r<tl){
		return 0;
	}
	if(l<=tl && tr<=r){
		return t[v];
	}
	int tm=(tl+tr)>>1;
	int ans=0;
	ans+=query(v<<1,tl,tm,l,r);
	ans+=query(v<<1|1,tm+1,tr,l,r);
	return ans;
}
void update(int v,int tl,int tr,int idx,int val){
	if(tr<idx || idx<tl){
		return;
	}
	if(tl==tr && tl==idx){
		t[v]=val;
		return;
	}
	int tm=(tl+tr)>>1;
	update(v<<1,tl,tm,idx,val);
	update(v<<1|1,tm+1,tr,idx,val);
	merge(v);
}
void solve(){
	int nq;
	cin >> n >> nq;
	a.assign(n,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<vector<int>> qu;
	qu.assign(nq,vector<int>(3));
	for(int i=0;i<nq;i++){
		for(int j=0;j<3;j++){
			cin >> qu[i][j];
		}
	}
	build();
	for(auto q:qu){
		if(q[0]==1){
			update(1,0,n-1,q[1]-1,q[2]);
		}
		else{
			cout << query(1,0,n-1,q[1]-1,q[2]-1) << "\n";
		}
	}
}

int main(){
	solve();
}