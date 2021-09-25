#include<bits/stdc++.h>
using namespace std;

void kth_ancestor(int u,int k){
	vector<int> parent;
	int l=log2(n);
	int dp[n+1][l+1];
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][0]=parent[i];
	}
	for(int j=1;j<=l;j++){
		for(int i=1;i<=n;i++){
			if(dp[i][j-1]!=-1){
				dp[i][j]=dp[dp[i][j-1]][j];
			}
		}
	}
	for(int i=20;i>=0;i--){
		if(k&(1ll<<i)){
			u=dp[u][i];
		}
		if(u==-1){
			break;
		}
	}
	cout << u << '\n';
}

int main(){
	
}
