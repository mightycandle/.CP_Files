#include<bits/stdc++.h>
using namespace std;
// 0-1 Knapsack with max W

int knapsack(vector<int> weights,vector<int> values,int W,int n=0){
	n=weights.size();
	vector<vector<int>> dp(n,vector<int>(W+1));
	dp[0][weights[0]]=values[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=W;j++){
			dp[i][j]=dp[i-1][j];
			if(j-weights[i]>=0){
				dp[i][j]=max(dp[i][j],values[i]+dp[i-1][j-weights[i]]);
			}
		}
	}
	int ans=0;
	for(int j=0;j<=W;j++){
		ans=max(ans,dp[n-1][j]);
	}
	return ans;
}

int main(){

}