#include<bits/stdc++.h>
using namespace std;

bool is_pal(string s){
	if(s.empty()){
		return 0;
	}
	string r=s;
	reverse(all(r));
	return r==s;
}

int main(){

}