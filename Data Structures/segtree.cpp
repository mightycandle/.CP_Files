#include<bits/stdc++.h>
using namespace std;

class Segtree{
	int n;
	vector<int> a;
	vector<int> t;
	int reset=0;
public:
	Segtree(vector<int> _a={0}){
		a=_a;
		if(a.empty()){
			a={0};
		}
		build();
	}
	void merge(int i){
		// condition for merge
	}
	void build(){
		n=a.size();
		while(n&(n-1)){
			a.push_back(0);n++;
		}
		t.assign(n<<1,0);
		for(int i=n;i<(n<<1);i++){
			t[i]=a[i-n];
		}
		for(int i=n-1;i>0;i--){
			merge(i);
		}
	}
	void update(int pos,int val){
		auto _merge=[&](int i)->void{
			merge(i);
		};
		auto u=[&](int v,int l,int r,int i,int k,auto&& u)->void{
			if(i<l or i>r){
				return;
			}
			else if(i==l and i==r){
				t[v]=k;
			}
			else{
				int m=(l+r)>>1;
				u(v<<1,l,m,i,k,u);
				u(v<<1|1,m+1,r,i,k,u);
				_merge(v);
			}
		};
		u(1,0,n-1,pos,val,u);
	}
	int query(int l,int r){
		int ans=reset;
		auto _merge=[&](int i)->void{
			merge(i);
		};
		auto q=[&](int v,int tl,int tr,int l,int r,auto&& q)->void{
			if(r<tl or tr<l){
				return;
			}
			else if(l<=tl and tr<=r){
				// merge ans with t[v]
			}
			else{
				int tm=(tl+tr)>>1;
				q(v<<1,tl,tm,l,r,q);
				q(v<<1|1,tm+1,tr,l,r,q);
			}
		};
		q(1,0,n-1,l,r,q);
		return ans;
	}
};

int main(){
	
}