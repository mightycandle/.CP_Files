#include<bits/stdc++.h>
using namespace std;
namespace Force{
	namespace Custom{
		#define rep(i,a,b)  for(int i=a;(a<b)?i<b:i>b;(a<b)?i++:i--)
		#define  revit(a)   for(auto it=a.begin();it!=a.end();it++)
		#define   rall(a)   reverse((a).begin(),(a).end())
		#define    all(a)   a.begin(),a.end()
		#define  each(x,a)  for(auto x:a)
		#define make(a,b,c) a.assign(b,c)

		#define tcT  template<class T>
		#define tcTU template<class T,class U>
		#define tcTA template<class T,class ... Args>
		#define read(T, ...) T __VA_ARGS__;rd(__VA_ARGS__)

		#define ll  long long
		#define vi  vector<int>
		#define vb  vector<bool>
		#define pii pair<int,int>
		#define vvi vector<vector<int>>
		#define pb  push_back
		tcT  using  V  = vector<T>;
		tcT  using  VV = vector<V<T>>;
		tcT  using pri = priority_queue<T>;
		tcT  using rpi = priority_queue<T,V<T>,greater<T>>;
	}
	using namespace Custom;
	namespace Debug{
		#define nex cout << "\n";
		#ifdef local
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
		void subl(){
			#ifdef fio
				freopen(".in","r",stdin);freopen(".out","w",stdout);
			#endif
		}
	}
	using namespace Debug;
	namespace IO{
		tcT  void rd(T& a){cin>>a;}
		tcT  void rd(V<T>& a){for(auto &x:a)rd(x);}
		tcT  void rd(VV<T>& a){for(auto &x:a)rd(x);}
		tcTU void rd(pair<T,U>& p){for(auto &x:p)rd(x);}
		tcTA void rd(T& a,Args&... args){cin>>a;rd(args...);}

		tcT  void print(T a,char sep='\n'){cout<<a<<sep;}
		tcT  void print(V<T> a,int r=0){int n=a.size();rep(i,r,n)cout<<a[i]<<" \n"[i==n-1];}
		tcT  void print(VV<T> a){each(x,a){print(x);}}
		tcTU void print(pair<T,U> p){cout<<p.first<<' '<<p.second<<"\n";}
		tcTA void print(T a,Args... args){cout<<a<<' ';print(args...);}
	}
	using namespace IO;
	namespace Helper{
		tcTU  void  amin(T& a,U b){if(a>b)a=b;}
		tcTU  void  amax(T& a,U b){if(a<b)a=b;}
		tcTU double pdiv(T a,U b){return (1.0*a)/(1.0*b);}
		tcT  T min(V<T> a){return *min_element(all(a));} 
		tcT  T max(V<T> a){return *max_element(all(a));}
		tcTU T min(T a,U b){if(a>b)a=b;return a;}
		tcTU T max(T a,U b){if(a<b)a=b;return a;}
		tcT int lwb(V<T> a,T x){return lower_bound(all(a),x)-a.begin();}
		tcT int upb(V<T> a,T x){return upper_bound(all(a),x)-a.begin();}
		int ceil(int a,int b){return (a+b-1)/b;}
		void yes(){cout << "YES" << "\n";}
		void  no(){cout << "NO" << "\n";}
	}
	using namespace Helper;
}
using namespace Force;

void solve(){
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T=1;
	cin >> T;
	
	for(int i=1;i<=T;i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}