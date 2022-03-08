#include<bits/stdc++.h>
using namespace std;
// return contig. counts of values and the no-rep vector

void uniqcnts(vector<int> a){
	vector<int> r={a[0]};
	vector<int> cnt={1};
	for(int i=1;i<a.size();i++){
		if(a[i]!=r.back()){
			r.push_back(a[i]);
			cnt.push_back(1);
		}
		else cnt.back()++;
	}
	int m=cnt.size();
}

void uniqcnts(string s){
	string r="";r+=s[0];
	vector<int> cnt={1};
	for(int i=1;i<s.size();i++){
		if(s[i]!=r.back()){
			r+=s[i];
			cnt.push_back(1);
		}
		else cnt.back()++;
	}
	int m=cnt.size();
}

int main(){
	
}
