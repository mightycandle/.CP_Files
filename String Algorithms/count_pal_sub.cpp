#include<bits/stdc++.h>
using namespace std;
// count palindromic substrings in O(N^2)

int count_pals(string s){
	int n=s.size();
	vector<vector<bool>> dp(n,vector<bool>(n+1));
	for(int i=0;i<n;i++){
		dp[i][0]=1,dp[i][1]=1;
	}
	for(int j=2;j<=n;j++){
		for(int i=0;i<=n-j;i++){
			dp[i][j]=((s[i]==s[i+j-1]) && dp[i+1][j-2]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			ans+=dp[i][j];
		}
	}
	return ans;	
}

int main(){

}