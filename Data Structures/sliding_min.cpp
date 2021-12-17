#include<bits/stdc++.h>
using namespace std;

vector<int> sliding_minimum(vector<int> a,int k){
	int n=a.size();
	deque<int> q;
	vector<int> ans;
	for(int i=0;i<n;i++){
		while(!q.empty() && a[i]<a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		while(i-q.front()>=k){
			q.pop_front();
		}
		if(i>=k-1){
			ans.push_back(a[q.front()]);
		}
	}
	return ans;
}

int main(){
	
}