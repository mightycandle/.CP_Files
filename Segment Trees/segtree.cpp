#include<bits/stdc++.h>
using namespace std;

class Segtree{
	int n;
	vector<int> a;
	vector<int> t;
	int reset;
	int answer;
public:
	Segtree(int n,vector<int> a){
		this->n=n;
		this->a=a;
	}
	int merge(int i,int type=0){
		if(type==0){
			return t[i]; //fill operation for tree
		}
		return t[i];//replace operation for result
	}
	void build(){
		while(n&(n-1)){
			n++;
		}
		a.resize(n);
		t.assign(n<<1,0);
		for(int i=0;i<n;i++){
			t[i+n]=a[i];
		}
		for(int i=n-1;i>=1;i--){
			int tmp=merge(i);
		}
	}
	void update(int v,int tl,int tr,int pos,int val){
		if(pos<tl || pos>tr){
			return;
		}
		if(pos==tl && tl==tr){
			t[v]=val;
			return;
		}
		int tm=(tl+tr)>>1;
		update(v<<1,tl,tm,pos,val);
		update(v<<1|1,tm+1,tr,pos,val);
		merge(v);
	}
	void query(int v,int tl,int tr,int l,int r){
		if(r<tl || l>tr){
			return;
		}
		if(l<=tl && r>=tr){
			merge(answer,t[v]);
		}
		int tm=(tl+tr)>>1;
		query(v<<1,tl,tm,l,r);
		query(v<<1|1,tm+1,tr,l,r);
	}
	int get_res(){
		int tmp=answer;
		answer=reset;
		return tmp;
	}
};

int main(){
	
}