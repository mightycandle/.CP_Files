#include <bits/stdc++.h>
using namespace std;
// operations w/ power set. traverse every bit and check from 0-n

void PowerSet(vector<int> a)
{
	int n = a.size();
	vector<vector<int>> pset;
	for (int bit = 0; bit < (1LL << n); bit++) {
		vector<int> cur;
		for (int idx = 0; idx < n; idx++) {
			if (bit & (1 << idx)) {
				cur.push_back(a[idx]);
			}
		}
		pset.push_back(cur);
	}
}

int main()
{
}
