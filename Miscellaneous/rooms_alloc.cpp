#include<bits/stdc++.h>
using namespace std;
// Room allocation: rooms req = max(dp)

vector<int> rooms(vector<int> start,vector<int> end){
	int n=start.size();
	multimap<pair<int,int>,int> mp;
	for(int i=0;i<n;i++){
		mp.insert({{start[i],end[i]},i});
	}
	int cnt=0;
	vector<int> dp(n);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(auto it=mp.begin();it!=mp.end();it++){
		int c=it->second;
		if(pq.empty() || pq.top().first>=(it->first.first)){
			c=++cnt;
		}
		else{
			c=pq.top().second;
			pq.pop();
		}
		pq.push({it->first.second,c});
		dp[it->second]=c;
	}
	return dp;
}

int main(){

}