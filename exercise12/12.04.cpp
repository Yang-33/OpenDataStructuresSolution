#include<bits/stdc++.h>
using namespace std;

int main() {
	// check G: connected? 
	// we can check by bfs or dfs.

	const int N = 10;
	vector<vector<int>>Graph(N); // need input !

	int color = 0;
	vector<int>visit_color(N, -1);

	function<void(int, int)>dfs = [&](int current, int previous) {
		visit_color[current] = color;
		for (auto next_v : Graph[current]) {
			if (next_v == previous)continue;
			if (visit_color[next_v] != -1)continue;
			dfs(next_v, current);
		}
	};

	for (int v = 0; v < N; v++) {
		if (visit_color[v] == -1) {
			dfs(v, -1);
			color++;
		}
	}
	if (color == 1)puts("Given graph is connected.");
	else puts("Given graph is not connected.");

}
