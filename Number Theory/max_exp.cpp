#include <bits/stdc++.h>
using namespace std;
vector<int> factors(int n) { return {}; };
// pre-req: sieve and primefactors function

int max_exp(int n, int m)
{
	vector<int> fac1 = factors(n);
	map<int, int> cnt;
	for (auto x : fac1) {
		cnt[x] += 1;
	}
	vector<int> fac2 = factors(m);
	int ans = INT_MAX;
	for (auto x : fac2) {
		ans = min(ans, cnt[x]);
	}
	return (ans == INT_MAX) ? 0 : ans;
}

int main()
{
}
