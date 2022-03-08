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
		int above=(s[i]-'0')-carry;
		int below=t[i]-'0';
		carry=(above<below)?1:0;
		ans+=char('0'+(above-below+10*carry));
	}
	while(ans.back()=='0' and !ans.empty()){
		ans.pop_back();
	}
	if(not ans.empty()){
		reverse(ans.begin(),ans.end());
	}
	return ans;
}

int main(){
	
}