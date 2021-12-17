#include<bits/stdc++.h>
using namespace std;
// static range minimum queries

int n,res;
vector<int> a;
vector<int> t;
void merge(int i){
	t[i]=min(t[i<<1],t[i<<1|1]);
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
void query(int v,int tl,int tr,int l,int r){
	if(tr<l || r<tl){
		return;
	}
	if(l<=tl && tr<=r){
		res=min(res,t[v]);
		return;
	}
	int tm=(tl+tr)>>1;
	query(v<<1,tl,tm,l,r);
	query(v<<1|1,tm+1,tr,l,r);
}
void solve(){
	int nq;
	cin >> n >> nq;
	a.resize(n,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<vector<int>> qu;
	qu.assign(nq,vector<int>(2));
	for(int i=0;i<nq;i++){
		for(int j=0;j<2;j++){
			cin >> qu[i][j];
		}
	}
	build();
	for(auto q:qu){
		res=INT_MAX;
		query(1,0,n-1,q[0]-1,q[1]-1);
		cout << res << "\n";
	}
}

int main(){
	solve();
}