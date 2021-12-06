#include<bits/stdc++.h>
using namespace std;

const int N=1e3+3;
int ncr[N][N];
void fill_ncr(){
	ncr[0][0]=1;
	for(int i=1;i<N;i++){
		ncr[i][0]=ncr[i][i]=1;
		for(int j=1;j<N;j++){
			// check if you have to mod here
			ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
		}
	}
}

int main(){
	
}