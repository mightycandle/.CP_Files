#include<bits/stdc++.h>
using namespace std;
// returns 1 if first is lesser (fless)
string alphabets="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string vowels="AEIOU";

bool cmp(string s,string t){
	int n=s.size();
	int m=t.size();
	for(int i=0;i<min(n,m);i++){
		if(s[i]!=t[i]){
			return s[i]<t[i];
		}
	}
	return n<=m;
}

int main(){

}