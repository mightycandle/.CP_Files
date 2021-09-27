#include<bits/stdc++.h>
using namespace std;

void uniqcnts(vector<int> a){
	vector<int> uni={a[0]};
	vector<int> cnts={1};
	for(int i=1;i<(int)a.size();i++){
		if(a[i]!=uni.back()){
			uni.push_back(a[i]);
			cnts.push_back(1);
		}
		else cnts.back()++;
	}
}

int main(){
	
}