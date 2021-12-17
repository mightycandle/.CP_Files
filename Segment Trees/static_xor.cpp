#include<bits/stdc++.h>
using namespace std;

int xors;
vector<int> t;

void merge(int i){
	t[i]=t[i<<1]^t[i<<1|1];
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

void query(int node,int tl,int tr,int l,int r){
	if(tl>=l && tr<=r){
		xors=xors^t[node];
		return;
	}
	if(tl>r || tr<l){
		return;
	}
	int tm=(tl+tr)>>1;
	query(node<<1,tl,tm,l,r);
	query(node<<1|1,tm+1,tr,l,r);
	merge(node);
}

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(auto &it:a){
		cin>>it;
	}
	vector<vector<int>> qu(q,vector<int>(2));
	for(int i=0;i<q;i++){
		cin>>qu[i][0]>>qu[i][1];
	}
 
 	build(a,n);
 	for(vector<int> vq:qu){
 		xors=0;
 		query(1,0,n-1,vq[0]-1,vq[1]-1);
 		cout<<xors<<'\n';
 	}
	return 0;
}