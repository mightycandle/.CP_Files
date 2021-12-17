#include<bits/stdc++.h>
using namespace std;
// Lazy prop. segment tree for dynamic sum

vector<int> t,upd;
vector<bool> lazy;
void merge(int i){
	t[i]=t[i<<1]+t[i<<1|1];
}
void build(vector<int>& a,int& n){
	while(n&(n-1)){
		n++;
		a.push_back(0);
	}
	t.assign(n<<1,0);
	for(int i=n;i<(n<<1);i++){
		t[i]=a[i-n];
	}
	for(int i=n-1;i>0;i--){
		merge(i);
	}
}
void apply(int v,int tl,int tr,int val){
	t[v]+=val*(tr-tl+1);
	if(tr==tl){
		return;
	}
	upd[v]+=val;
	lazy[v]=1;
}
void pushdown(int v,int tl,int tr){
	if(lazy[v]==0){
		return;
	}
	lazy[v]=0;
	int tm=(tl+tr)>>1;
	apply(v<<1,tl,tm,upd[v]);
	apply(v<<1|1,tm+1,tr,upd[v]);
	merge(v);
	upd[v]=0;
}
void update(int v,int tl,int tr,int l,int r,int val){
	if(tl>r || tr<l){
		return;
	}
	if(l<=tl && tr<=r){
		apply(v,tl,tr,val);
		return;
	}
	pushdown(v,tl,tr);
	int tm=(tl+tr)>>1;
	update(v<<1,tl,tm,l,r,val);
	update(v<<1|1,tm+1,tr,l,r,val);
	merge(v);
}
int query(int v,int tl,int tr,int idx){
	if(tl>idx || tr<idx){
		return 0;
	}
	if(idx==tl && tr==idx){
		return t[v];
	}
	pushdown(v,tl,tr);
	int tm=(tl+tr)>>1;
	int ans=0;
	ans+=query(v<<1,tl,tm,idx);
	ans+=query(v<<1|1,tm+1,tr,idx);
	merge(v);
	return ans;
}

void init(vector<int>& a,int& n){
	build(a,n);
	lazy.assign(n<<1,0);
	upd.assign(n<<1,0);

	/*
	QUERIES:
	1. Update: <L,R> by +Value
		update(1,0,n-1,L,R,Value)
	2. Query: index
		cout << query(1,0,n-1,index) << '\n'
	*/
}

int main(){

}