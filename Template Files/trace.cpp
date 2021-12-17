#include<bits/stdc++.h>
using namespace std;

#ifdef vim
	#define trace(...) db(#__VA_ARGS__, __VA_ARGS__)
	template<typename T> void db(const char* x,T&& a){
		cerr << x << " = " << a <<"\n";
	}
	template<typename T,typename ...Args>
	void db(const char* x,T&& a,Args&&... args){
		const char* dn=strchr(x+1,',');
		cerr.write(x,dn-x) << " = " << a << " | ";
		db(dn+1,args...);
	}
	template<typename T> void db(const char* x,vector<T> v){
		cerr << x << " = ";
		for(auto x:v){
			cerr << x << ' ';
		}
		cerr << "\n";
	}
#else
	#define trace(...) 1
#endif

int main(){
	
}