#include<bits/stdc++.h>
using namespace std;

int main() {
	// universal sink.
	// we want to find [1111..]^t and [...0000] with O(N).
	// There is one or zero universal sink in graph.
	// That is hint.
	// - Useful link: http://web.mst.edu/~ercal/253/SLIDES/PDF/Lec-22.pdf

	using Graph = vector<vector<int>>;

	const int N = 10;
	Graph graph(N, vector<int>(N, 0));
	// need input!

	auto is_v_universal_sink = [&](int v) {
		for (int j = 0; j < v; j++) {
			if (graph[v][j])return false;
		}
		for (int i = 0; i < v; i++) {
			if (graph[v][i] == 0 and i != v)return false;
		}
		return true;
	};

	auto is_graph_universal_sink = [&]() {
		int i = 0, j = 0;
		while (i < N and j < N) {
			if (graph[i][j] == 1) {
				i++;
			}
			else {
				j++;
			}
		}
		if (i == N)return false;
		else return is_v_universal_sink(i);
	};

}
