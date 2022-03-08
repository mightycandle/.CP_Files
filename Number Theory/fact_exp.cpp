#include<bits/stdc++.h>
using namespace std;
// exponent of m in n!

int fact_exp(int n,int k){
	int cnt=0;
	while(n>0){
		n/=k,cnt++;
	}
	return cnt;
}

int main(){

}