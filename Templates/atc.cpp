#include<bits/stdc++.h>
using namespace std;
namespace Force{
	namespace Custom{
		#define rep(i,a,b)  for(int i=a;(a<b)?i<b:i>b;(a<b)?i++:i--)
		#define  revit(s)   for(auto it=s.begin();it!=s.end();it++)
		#define    all(a)   a.begin(),a.end()
		#define  each(x,v)  for(auto x:v)
		#define make(a,b,c) a.assign(b,c)

		#define tcT  template<class T>
		#define tcTU template<class T,class U>
		#define tcTA template<class T,class ... Args>
		#define read(T, ...) T __VA_ARGS__;rd(__VA_ARGS__)
	}
	using namespace Custom;

	namespace TypeDef{
		#define ll  long long
		#define vi  vector<int>
		#define vvi vector<vi>
		#define pb  push_back

		tcTU using  M  = map<T,U>;
		tcT  using  V  = vector<T>;
		tcTU using  P  = pair<T,U>;
		tcT  using  VV = vector<V<T>>;
		tcT  using pri = priority_queue<T>;
		tcT  using rpi = priority_queue<T,V<T>,greater<T>>;
	}
	using namespace TypeDef;

	namespace Debug{
		#ifdef vim
			#define trace(...) dbg(#__VA_ARGS__, __VA_ARGS__)
			tcT void dbg(const char* name,T&& a){
				cerr << name << " is " << a << "\n";
			}
			tcTA void dbg(const char* names,T&& a,Args&&... args){
				const char* comma=strchr(names+1,',');
				cerr.write(names,comma-names)<<" is "<< a <<" | ";
				dbg(comma+1,args...);
			}
			tcT void dbg(const char* name,vector<T> v){
				cerr<<name<<" : ";each(x,v)cerr<<x<<' ';cerr<<"\n";
			}
		#else
			#define trace(...) 1
		#endif
	}
	using namespace Debug;

	namespace IO{
		tcT  void rd(T& a){cin>>a;}
		tcT  void rd(V<T>& a){for(auto &x:a)rd(x);}
		tcT  void rd(VV<T>& a){for(auto &x:a)rd(x);}
		tcTU void rd(pair<T,U>& p){for(auto &x:p)rd(x);}
		tcTA void rd(T& a,Args&... args){cin>>a;rd(args...);}

		tcT  void print(T a,char sep='\n'){cout<<a<<sep;}
		tcT  void print(V<T> a){each(x,a){cout<<x<<' ';}cout<<"\n";}
		tcT  void print(VV<T> a){each(x,a){print(x);}}
		tcTU void print(pair<T,U> p){cout<<p.first<<' '<<p.second<<"\n";}
		tcTA void print(T a,Args... args){cout<<a<<' ';print(args...);}
	}
	using namespace IO;

	namespace Helper{
		int ceil(int a,int b){return (a+b-1)/b;}
		void yes(){cout << "YES" << "\n";}
		void  no(){cout << "NO" << "\n";}

		tcT  T min(V<T> a){return *min_element(all(a));} 
		tcT  T max(V<T> a){return *max_element(all(a));}
		tcTU T min(T a,U b){if(a>b)a=b;return a;}
		tcTU T max(T a,U b){if(a<b)a=b;return a;}

		tcTU  void  amin(T& a,U b){if(a>b)a=b;}
		tcTU  void  amax(T& a,U b){if(a<b)a=b;}
		tcTU double pdiv(T a,U b){return (1.0*a)/(1.0*b);}
	}
	using namespace Helper;
}
using namespace Force;

void solve(){
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef local
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
	
	solve();
}