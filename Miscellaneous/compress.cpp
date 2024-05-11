#include <bits/stdc++.h>
using namespace std;
// scale down values of vector within its length

void compress(vector<int>& a)
{
	set<int> s;
	for (auto x : a) {
		s.insert(x);
	}
	map<int, int> convert, invert;
	int cur = 1;
	for (auto it = s.begin(); it != s.end(); it++) {
		convert[*it] = cur;
		invert[cur] = *it;
		cur++;
	}
	for (auto& x : a) {
		x = convert[x];
	}
}

int main()
{
}
