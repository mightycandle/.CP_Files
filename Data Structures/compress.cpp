#include<bits/stdc++.h>
using namespace std;

void compress(vector<int>& a){
	set<int> s;
	for(auto x:a){
		s.insert(x);
	}
	map<int,int> change;
	int cur=0;
	for(auto it=s.begin();it!=s.end();it++){
		change[*it]=cur++;
	}
	for(auto &x:a){
		x=change[x];
	}
}

int main(){
	
}