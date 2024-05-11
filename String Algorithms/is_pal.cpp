#include <bits/stdc++.h>
using namespace std;

bool is_pal(string s)
{
	if (s.empty()) {
		return 0;
	}
	string r = s;
	reverse(r.begin(), r.end());
	return r == s;
}

int main()
{
}
