#include<bits/stdc++.h>

long long sqrt(long long n){
	long long l=0,r=n;
	while(l<=r){
		long long m=(l+r)>>1;
		if(m*m==n or (m*m<n and (m+1)*(m+1)>n)){
			return m;
		}
		if(m*m>n){
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return l;
}

int main(){
	
}