#include<bits/stdc++.h>
using namespace std;
// returns the prefix array of hash values of the string
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

vector<long long> hash_string(string s){
	int n=s.size();
	vector<long long> res(n);
	for(int i=0;i<n;i++){
		res[i]=((s[i]-'a'+1)*1LL*ppow[i])%mod;
	}
	for(int i=1;i<n;i++){
		res[i]=(res[i]+res[i-1]+mod)%mod;
	}
	return res;
}

int main(){

}