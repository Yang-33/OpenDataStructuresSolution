#include<bits/stdc++.h>
using namespace std;

int main() {
	// we can appay some shortest pash algorithm to solve this problem.
	// For example, 
	// - Dijkstra's algorithm
	// - SPFA
	// - Bellman-Ford
	// - Warshall Floyd
	
	// There are some algorithms. 
	// As an example, I write Dijkstra's algorithm.

	auto Dijkstra = [](const vector<vector<int>>& graph, int s) {

		struct node {
			int v, cost_sum;
			node(int vv, int cost) :v(vv), cost_sum(cost) {}
			bool operator > (const node& x)const {
				return this->cost_sum > x.cost_sum;
			}
		};
		priority_queue<node, vector<node>, greater<node>> que;

		vector<int> dist((int)graph.size(), 1e9);

		dist[s] = 0;
		que.emplace(0, s);

		while (!que.empty()) {
			node p = que.top(); que.pop();
			if (p.cost_sum > dist[p.v]) continue;

			for (int next_v : graph[p.v]) {
				if (dist[next_v] > p.cost_sum + 1) {
					dist[next_v] = p.cost_sum + 1;
					que.emplace(dist[next_v], next_v);
				}
			}
		}
		return dist;
	};

}
