#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int madd(int a,int b){a=(a+0ll+b)%mod;return (a<0)?a+mod:a;}
void madd(int& a,int b){a=(a+0ll+b)%mod;a=(a<0)?a+mod:a;}

int msub(int a,int b){a=(a+0ll-b)%mod;return (a<0)?a+mod:a;}
void msub(int& a,int b){a=(a+0ll-b)%mod;a=(a<0)?a+mod:a;}

int mmul(int a,int b){a=(a*1ll*b)%mod;return (a<0)?a+mod:a;}
void mmul(int& a,int b){a=(a*1ll*b)%mod;a=(a<0)?a+mod:a;}

int main(){
	
}