#include<bits/stdc++.h>
using namespace std;
// check bounds of N before use
// int -> long long

vector<long long> ppow;
const int N=1e6+6;
int mod=1e9+7,p=31;

void init(){
	ppow.assign(N,1);
	for(int i=1;i<N;i++){
		ppow[i]=(ppow[i-1]*1LL*p)%mod;
	}
}

long long hash_score(string s){
	int n=s.size();
	long long ans=0;
	for(int i=0;i<n;i++){
		ans=(ans+((s[i]-'a'+1)*1LL*ppow[i])+mod)%mod;
	}
	return ans;
}

int main(){

}