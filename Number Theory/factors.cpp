#include <bits/stdc++.h>
using namespace std;
// factors of a number

vector<int> factorization(int n)
{
	set<int> s;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			s.insert(i);
			if (i != (n / i)) {
				s.insert(n / i);
			}
		}
	}
	vector<int> a;
	for (auto it = s.begin(); it != s.end(); it++) {
		a.push_back(*it);
	}
	return a;
}

int main()
{
}
