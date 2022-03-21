// user: _shanks_ ; sashank1711

#include <bits/stdc++.h>
using namespace std;

#define tcT  template<class T>
#define tcTU template<class T,class U>
#define tcTA template<class T,class ... Args>

tcT using  V  = vector<T>;
tcT using  VV = vector<vector<T>>;
tcT using rpi = priority_queue<T,vector<T>,greater<T>>;
#pragma GCC diagnostic ignored "-Wreturn-type"


#define _(...) dbg(#__VA_ARGS__, __VA_ARGS__)


tcT void dbg(const char* id,T&& a){
	cerr << id << " is " << a << '\n';
}
tcTA void dbg(const char* id,T&& a,Args&&... args){
	const char* comma=strchr(id+1,',');
	cerr.write(id,comma-id) << " is " << a <<" | ";
	dbg(comma+1,args...);
}
tcT void dbg(const char* id,vector<T> a){
	cerr << id << ": ";
	for(auto it=a.begin();it!=a.end();it++){
		cerr << *it << " \n"[it+1==a.end()];
	}
}
tcT void dbg(const char* id,VV<T> v){
	cerr << id << ": \n";
	for(auto y:v){
		for(auto it=y.begin();it!=y.end();it++){
			cerr << ' ' << *it << " \n"[it+1==y.end()];
		}
	}
}
tcTU void dbg(const char* id,vector<pair<T,U>> v){
	cerr << id << ":\n";
	for(auto p:v){
		cerr << " {" << p.first << ", " << p.second << "}\n";
	}
}
tcTU void dbg(const char* id,pair<T,U> p){
	cerr << id << ": {" << p.first << ", " << p.second << "}\n";
}
tcTU void dbg(const char* id,map<T,U> mp){
	cerr << id << ":\n";
	for(auto p:mp){
		cerr << " {" << p.first << " -> " << p.second << "}\n";
	}
}
tcT void dbg(const char* id,set<T> s){
	cerr << id << ": ";
	for(auto it=s.begin();it!=s.end();it++){
		cerr << *it << ' ';
	}
	cerr << '\n';
}
tcTU void dbg(const char* id,set<pair<T,U>> s){
	cerr << id << ": \n";
	for(auto it=s.begin();it!=s.end();it++){
		cerr << "{" << (*it).first << ", " << (*it).second << "}\n";
	}
}

tcT void dbg(const char* id,multiset<T> s){
	cerr << id << ": ";
	for(auto it=s.begin();it!=s.end();it++){
		cerr << *it << ' ';
	}
	cerr << '\n';
}
tcT void dbg(const char* id,queue<T> q){
	cerr << id << ": ";
	while(not q.empty()){
		cerr << q.front() << ' ';
		q.pop();
	}
	cerr << '\n';
}
tcT void dbg(const char* id,stack<T> s){
	cerr << id << ": ";
	while(not s.empty()){
		cerr << s.top() << ' ';
		s.pop();
	}
	cerr << '\n';
}
tcT void dbg(const char* id,priority_queue<T> pq){
	cerr << id << ": ";
	while(not pq.empty()){
		cerr << pq.top() << ' ';
		pq.pop();
	}
	cerr << '\n';
}
tcT void dbg(const char* id,rpi<T> pq){
	cerr << id << ": ";
	while(not pq.empty()){
		cerr << pq.top() << ' ';
		pq.pop();
	}
	cerr << '\n';
}
tcTU void dbg(const char* id,priority_queue<pair<T,U>> pq){
	cerr << id << ": ";
	while(not pq.empty()){
		cerr << "{" << pq.top().first << ", " << pq.top().second << "}\n";
		pq.pop();
	}
}

// just so you know
void setBit(int& n,int x){
	n|=(1<<x);
}
void unsetBit(int& n,int x){
	n&=~(1<<x);
}
void toggleBit(int& n,int x){
	n^=(1<<x);
}
bool getBit(int n,int x){
	return n&(1<<x);
}
void leftShift(int& n,int x){
	n<<=(1<<x);
}
void rightShift(int& n,int x){
	n>>=(1<<x);
}
int oneBits(int n){
	return __builtin_popcountll(n);
}
int lsb(int n){
	return __builtin_ctzll(n);
}
int msb(int n){
	return log2(n);
}
