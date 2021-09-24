#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int mod=1e9+7;
int p=31;
vector<int> ppow;
void Hash(string s){
	if(ppow.empty()){
		ppow.assign(N,1);
		for(int i=1;i<N;i++){
			ppow[i]=(ppow[i-1]*p)%mod;
		}
	}
	int n=s.size();
	vector<int> ref(n+1);
	for(int i=0;i<n;i++){
		ref[i+1]=(ref[i]+(ppow[i]*(s[i]-'a'+1)))%mod;
	}
}

int main(){
	
}
