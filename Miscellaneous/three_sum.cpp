#include<bits/stdc++.h>
using namespace std;
// three sum

vector<int> three_sum(vector<int> a,int k){
	int n=a.size();
	vector<vector<int>> big;
	for(int i=0;i<n;i++){
		big.push_back({a[i],i});
	}
	if(n==3){
		if(a[0]+a[1]+a[2]==k){
			return {a[0],a[1],a[2]};
		}
		else{
			return {};
		}
	}
	sort(big.begin(),big.end());
	for(int i=0;i<n;i++){
		int l=0,r=n-1,req=k-a[i];
		while(l<r){
			if(big[l][1]==i){
				l++;
			}
			else if(big[r][1]==i){
				r--;
			}
			else if(big[l][0]+big[r][0]>req){
				r--;
			}
			else if(big[l][0]+big[r][0]<req){
				l++;
			}
			else{
				return {a[i],a[big[l][1]],a[big[r][1]]};
			}
		}
	}
	return {};
}

int main(){
	
}