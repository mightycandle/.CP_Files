#include<bits/stdc++.h>
using namespace std;
// Rabin-Karp string matching

vector<long long> ppow;
const int N=1e6+6;
int mod=1e9+7,p=31;

vector<long long> hash_string(string s);
long long hash_score(string s);
void init();

int string_match(string s,string t){
	int n=s.size();
	int m=t.size();
	if(m>=n){
		return (s==t);
	}
	vector<long long> res=hash_string(s);
	long long hash_value=hash_score(t);
	int cnt=0;
	for(int i=0;i<n-m+1;i++){
		long long cur=(res[i+m-1]-(i?res[i-1]:0)+mod)%mod;
		if(cur==hash_value){
			cnt+=1;
		}
		hash_value=(hash_value*1LL*p)%mod;
	}
	return cnt;
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
long long hash_score(string s){
	int n=s.size();
	long long ans=0;
	for(int i=0;i<n;i++){
		ans=(ans+((s[i]-'a'+1)*1LL*ppow[i])+mod)%mod;
	}
	return ans;
}
void init(){
	ppow.assign(N,1);
	for(int i=1;i<N;i++){
		ppow[i]=(ppow[i-1]*1LL*p)%mod;
	}
}

int main(){

}