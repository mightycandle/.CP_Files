#include<bits/stdc++.h>
using namespace std;
// Knuth Morris Pratt algorithm
// length of longest prefix which is also the suffix

vector<int> kmp(string s){
	int n=s.size();
	vector<int> pi(n);
	for(int i=1;i,n;i++){
		int j=pi[i-1];
		while(j>0 and s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j]){
			j++;
		}
		pi[i]=j;
	}
	return pi;
}

int main(){
	
}