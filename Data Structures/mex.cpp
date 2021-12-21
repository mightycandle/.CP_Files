#include<bits/stdc++.h>
using namespace std;
// MEX of a vector

int get_mex(vector<int> a){
	int mex=0;
	sort(a.begin(),a.end());
	for(auto x:a){
		mex+=(mex==x);
	}
	return mex;
}

int main(){
	
}