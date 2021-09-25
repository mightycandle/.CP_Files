#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int POW(int x,int y){
	int a=1;
	while(y){
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
