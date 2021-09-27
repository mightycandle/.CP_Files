#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
void sieve(int n=1e6+6){
	primes.resize(n+1,0ll);
	primes[1]=1;
	for(int p=2;p*p<=n;p++){
		if(!primes[p]){
			primes[p]=p;
			for(int q=p*p;q<n+1;q+=p){
				primes[q]=p;
			}
		}
	}
	for(int p=2;p<=n;p++){
		if(!primes[p]){
			primes[p]=p;
		}
	}
}
#define isprime(x) ((x>1 && primes[x]==x)?1:0)

int main(){
	
}