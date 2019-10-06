#include<bits/stdc++.h>
using namespace std;

class StronglyConnectedComponentDecomposition {
private:
	const int n;
	vector<vector<int>> G;
	vector<vector<int>> rG;
	vector<int> vs;
	vector<bool> used;
	int sccsize_k;
public:
	StronglyConnectedComponentDecomposition(int _n) : n(_n), G(_n), rG(_n), used(_n) {}
	void addEdge(int from, int to) {
		G[from].emplace_back(to);
		rG[to].emplace_back(from);
	}
	void dfs(int v) {
		used[v] = true;
		for (auto&& nxt : G[v]) {
			if (!used[nxt]) dfs(nxt);
		}
		vs.emplace_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		for (auto&& nxt : rG[v]) {
			if (!used[nxt]) rdfs(nxt, k);
		}
		vs.emplace_back(v);
	}
	int decompose() {
		for (int v = 0; v < n; v++) {
			if (!used[v]) dfs(v);
		}
		used.assign(n, false);
		sccsize_k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			int v = vs[i];
			if (!used[v]) rdfs(v, sccsize_k++);
		}
		return sccsize_k;
	}
};

int main() {
	// we can solve this problem with 
	// strongry connected components decomposition.

	const int N = 10;
	StronglyConnectedComponentDecomposition Graph(N);

	// input: Graph.addEdge(from, to);
	int size = Graph.decompose();
	if (size == 1)puts("Given graph is strongly-connected");
	else puts("Given graph is not strongly-connected");
}
