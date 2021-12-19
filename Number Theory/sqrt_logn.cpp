#include<bits/stdc++.h>
using namespace std;
class SquareRoot {
public:
	int getSquareRoot(int num) {
	  int s = 0, e = num;
	  while(s <= e){
	  	int m = (s + e) / 2;
		if(1ll*m*m == num) return m;
		if(1ll*m*m < num and 1ll*(m+1)*(m+1) > num) return m;
		if(1ll*m*m > num) {
		  	e = m-1;
		}
		else {
			s = m+1;
		}
	  }
	}
};

long long sqrt(long long n){
	long long l=0,r=n;
	while(l<=r){
		long long m=(l+r)>>1;
		if(m*m==n){
			return m;
		}
		if(m*m<n and (m+1)*(m+1)>n){
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