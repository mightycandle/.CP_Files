#include<bits/stdc++.h>
using namespace std;

string subtract(string s,string t){
	if(s==t or s.empty() or t.empty()){
		return "0";
	}
	int n=s.size(),m=t.size();
	if(m>n){
		swap(s,t);
	}
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	t+=string(n-m,'0');
	string ans="";
	int carry=0;
	for(int i=0;i<n;i++){
		int top=(s[i]-'0')-carry;
		int bot=t[i]-'0';
		carry=(top<bot)?1:0;
		ans+=char('0'+(top-bot+carry*10));
	}
	while(ans.back()=='0' and !ans.empty()){
		ans.pop_back();
	}
	if(ans.empty()){
		ans="0";
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	
}