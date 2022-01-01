#include<bits/stdc++.h>
using namespace std;
// factors of a number

vector<int> factorization(int n){
	set<int> s;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			s.insert(i);
			s.insert(n/i);
		}
	}
	vi a;
	revit(s){
		a.pb(*it);
	}
	return a;
}

int main(){

}