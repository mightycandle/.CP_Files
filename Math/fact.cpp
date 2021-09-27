#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
vector<int> fact,Finv,Ninv;
void factfill(int n=1e6+6){
	fact.assign(n+1,1);
	Ninv.assign(n+1,1);
	Finv.assign(n+1,1);
	for(int i=2;i<=n;i++)
		fact[i]=(fact[i-1]*i)%mod;
	for(int i=2;i<=n;i++)
		Ninv[i]=Ninv[mod%i]*(mod-mod/i)%mod;
	for(int i=2;i<=n;i++)
		Finv[i]=(Ninv[i]*Finv[i-1])%mod;
}
#define nCr(n,r) (((fact[n]*Finv[r])%mod*Finv[n-r])%mod)

int main(){

}