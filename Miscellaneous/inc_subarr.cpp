#include<bits/stdc++.h>
using namespace std;
// lengths of segements of increasing subarrays

vector<int> inc_subarr(vector<int> a){
	int n=a.size();
	vector<int> dp(n,1);
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){
			dp[i]=dp[i-1]+1;
		}
	}
	vector<int> len(n,dp[n-1]);
	for(int i=n-2;i>=0;i--){
		if(dp[i]>1){
			len[i]=max(len[i+1],dp[i]);
		}
		else if(dp[i+1]>1){
			len[i]=len[i+1];
		}
		else{
			len[i]=dp[i];
		}
	}
	return len;
}

int main(){

}