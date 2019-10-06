#include<bits/stdc++.h>
using namespace std;

int main() {
	// dfs only check the edges of one spanning tree of given Graph.


	const int N = 10;
	vector<vector<int>>Graph(N); // need input !

	int color = 0;
	vector<int>visit_color(N, -1);

	using Tree = vector<vector<int>>;
	using Forest = vector<Tree>;

	Tree tree(N);
	Forest answer;
	function<void(int, int)>dfs = [&](int current, int previous) {
		visit_color[current] = color;
		for (auto next_v : Graph[current]) {
			if (next_v == previous)continue;
			if (visit_color[next_v] != -1)continue;
			tree[current].emplace_back(next_v);
			tree[next_v].emplace_back(current);
			dfs(next_v, current);
		}
	};

	for (int v = 0; v < N; v++) {
		if (visit_color[v] == -1) {
			dfs(v, -1);
			color++;
			answer.emplace_back(tree);
			tree = Tree(N);
		}
	}

	// ans: answer
}
