#include<bits/stdc++.h>
using namespace std;
// maximum subarray sum: kadane algorithm thing

int max_subarray(vector<int> a){
	int n=a.size();
	int ans=*max_element(a.begin(),a.end());
	if(ans<=0){
		return ans;
	}
	int cur=0;
	for(int i=0;i<n;i++){
		cur+=a[i];
		ans=max(ans,cur);
		if(cur<0){
			cur=0;
		}
	}
	return max(ans,cur);
}

int main(){
	
}