#include<bits/stdc++.h>
using namespace std;

string add(string s,string t){
	if(s=="0" or t=="0"){
		return (s=="0")?t:s;
	}
	int n=s.size(),m=t.size();
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	for(int i=min(n,m);i<max(n,m);i++){
		(n<m)?s+='0':t+='0';
	}
	string ans="";
	int carry=0;
	for(int i=0;i<n;i++){
		int res=(s[i]-'0')+(t[i]-'0')+carry;
		carry=res/10;
		ans+=char('0'+(res%10));
	}
	if(carry){
		ans+=char('0'+carry);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	
}