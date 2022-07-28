#include<bits/stdc++.h>
using namespace std;
// factors() is when sieve is done, and get_factors is generic
vector<int> primes;

vector<int> factors(int n){
	if(n==1){
		return {};
	}
	vector<int> factors;
	while(n>1){
		factors.push_back(primes[n]);
		n/=primes[n];
	}
	reverse(factors.begin(),factors.end());
	return factors;
}

vector<int> get_factors(int n){
	vector<int> factors;
	while(n%2==0){
		factors.push_back(2);
		n>>=1;
	}
	for(int i=3;i*i<=n;i+=2){
		while(n%i==0){
			factors.push_back(i);
			n/=i;
		}
	}
	if(n>1){
		factors.push_back(n);
	}
	return factors;
}

int main(){
	
}
