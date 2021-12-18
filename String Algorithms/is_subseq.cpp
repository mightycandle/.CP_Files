#include<bits/stdc++.h>
using namespace std;
// check if t is subsequence of s

bool is_subseq(string s,string t){
	int n=s.size();
	int m=t.size();
	if(m>n){
		return 0;
	}
	vector<vector<int>> cache(26);
	for(int i=0;i<n;i++){
		cache[s[i]-'a'].push_back(i);
	}
	int last=-1;
	for(int i=0;i<m;i++){
		int j=t[i]-'a';
		auto it=upper_bound(cache[j].begin(),cache[j].end(),last);
		if(it==cache[j].end()){
			return 0;
		}
		last=*it;
	}
	return 1;
}

int main(){

}