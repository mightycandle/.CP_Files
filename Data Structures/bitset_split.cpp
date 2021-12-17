#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
void subset_split(vector<int> a){
	int n=a.size();
	bitset<N> dp;
	dp.set(0);
	for(int i=0;i<n;i++){
		dp|=(dp<<a[i]);
	}
	int tot=0;
	for(int i=0;i<n;i++){
		tot+=a[i];
	}
	int x;
	int diff=INT_MAX;
	for(int i=0;i<N;i++){
		if(dp[i]==1){
			if(diff>abs(2*i-tot)){
				x=i;
				diff=abs(2*i-tot);
			}
		}
	}
	vector<int> split={x,tot-x};
}

int main(){
	
}