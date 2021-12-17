#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
	if((n&1)^1 || n<3){
		return (n==2);
	}
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){

}