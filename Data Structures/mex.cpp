#include<bits/stdc++.h>
using namespace std;
// MEX of an array

int get_mex(vector<int> a){
	int mex=0;
	sort(a.begin(),a.end());
	for(auto x:a){
		if(mex==x){
			mex++;
		}
	}
	return mex;
}

int main(){
	
}