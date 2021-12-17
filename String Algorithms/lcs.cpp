#include<bits/stdc++.h>
using namespace std;
// Longest common subsequence - O(N^2)

string lcs(string s,string t){
	int n=s.size();
	int m=t.size();
	if(!n or !m){
		return "";
	}
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	vector<vector<int>> track(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(s[i-1]==t[j-1]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
	}

	string ans="";
	for(int i=n,j=m;i>=1 and j>=1;){
		if(s[i-1]==t[j-1] and dp[i][j]>=max(dp[i-1][j],dp[i][j-1])){
			ans+=s[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){

}