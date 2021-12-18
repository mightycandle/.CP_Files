#include<bits/stdc++.h>
using namespace std;
// returns smallest prime divisor or -1 if prime

int min_prime(int n){
	if(n==2 or n==3){
		return -1;
	}
	if(n%2==0){
		return 2;
	}
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0){
			return i;
		}
	}
	return -1;
}

int main(){

}