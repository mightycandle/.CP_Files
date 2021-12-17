#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> a){
	vector<int> dp;
	for(auto x:a){
		auto it=lower_bound(dp.begin(),dp.end(),x);
		if(it==dp.end()){
			dp.push_back(x);
		}
		else *it=x;
	}
	return dp.size();
}

int main(){
	
}