#include<bits/stdc++.h>
using namespace std;

void list(vector<int> a){
	vector<int> dp;
	for(auto x:a){
		auto it=lower_bound(dp.begin(),dp.end(),x);
		if(it==dp.end()){
			dp.push_back(x);
		}
		else *it=x;
	}
}

int main(){
	
}