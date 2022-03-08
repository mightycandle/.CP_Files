#include<bits/stdc++.h>
using namespace std;
// merge overlapping intervals

vector<vector<int>> merge_intervals(vector<vector<int>> a){
	int n=a.size();
	sort(a.begin(),a.end());
	vector<vector<int>> dp;
	for(int i=0;i<n;){
		int start=a[i][0],end=a[i][1];
		int j=i+1;
		while(j<n && a[j][0]<=end){
			end=max(end,a[j++][1]);
		}
		dp.push_back({start,end});
		i=j;
	}
	return dp;
}

int main(){
	
}