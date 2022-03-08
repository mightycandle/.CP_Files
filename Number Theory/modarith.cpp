#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int madd(int a,int b){a=(a+0ll+b)%mod;return (a<0)?a+mod:a;}
void madd(int& a,int b){a=(a+0ll+b)%mod;a=(a<0)?a+mod:a;}

int msub(int a,int b){a=(a+0ll-b)%mod;return (a<0)?a+mod:a;}
void msub(int& a,int b){a=(a+0ll-b)%mod;a=(a<0)?a+mod:a;}

int mmul(int a,int b){a=(a*1ll*b)%mod;return (a<0)?a+mod:a;}
void mmul(int& a,int b){a=(a*1ll*b)%mod;a=(a<0)?a+mod:a;}

int POW(int x,int y){
	int a=1;
	while(y>0){
		if(y&1){
			a=(a*1ll*x)%mod;
		}
		x=(x*1ll*x)%mod;
		y>>=1;
	}
	return a;
}
#define INV(x) POW(x,mod-2)

int main(){
	
}