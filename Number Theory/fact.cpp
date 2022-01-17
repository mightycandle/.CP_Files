#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
vector<long long> fact,Finv,Ninv;
void factfill(int n=1e6+6){
    // do int -> long long and NO bit shift
	fact.assign(n+1,1LL);
	Ninv.assign(n+1,1LL);
	Finv.assign(n+1,1LL);
    for(int i=2;i<=n;i++){
        Ninv[i]=Ninv[mod%i]*(mod-mod/i)%mod;
    }
    for(int i=2;i<=n;i++){
        Finv[i]=(Ninv[i]*Finv[i-1])%mod;
    }
    for(int i=2;i<=n;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
#define nPr(n,r) ((fact[n]*Finv[r])%mod)
#define nCr(n,r) ((fact[n]*Finv[r])%mod*Finv[n-r])%mod
int main(){

}