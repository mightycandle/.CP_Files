#include <bits/stdc++.h>
using namespace std;
// returns distances from source
int n;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int s)
{
	vector<int> dist(n + 1, INT_MAX);
	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[s], s });
	vector<int> vis(n + 1);
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (vis[p.second]) {
			continue;
		}
		vis[p.second] = 1;
		for (auto v : adj[p.second]) {
			// if the graph is unweighted:
			//  v.first  --> v
			//  v.second --> 1
			if (dist[v.first] > dist[p.second] + v.second) {
				dist[v.first] = dist[p.second] + v.second;
				pq.push({ 0 - dist[v.first], v.first });
			}
		}
	}
	return dist;
}

int main()
{
}
