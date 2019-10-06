#include<bits/stdc++.h>
using namespace std;

int main() {
	// we can divide given graph to some connected graph

	const int N = 10;
	vector<vector<int>>Graph(N); // need input !

	int color = 0;
	vector<int>visit_color(N, -1);

	// Label color to each vertex.
	vector<int>temp_list;
	function<void(int, int)>dfs = [&](int current, int previous) {
		visit_color[current] = color;
		temp_list.emplace_back(current);
		for (auto next_v : Graph[current]) {
			if (next_v == previous)continue;
			if (visit_color[next_v] != -1)continue;
			dfs(next_v, current);
		}
	};

	vector<vector<vector<int>>> decomposed_graph;
	for (int v = 0; v < N; v++) {
		if (visit_color[v] == -1) {
			dfs(v, -1);

			{
				vector<vector<int>>will_push_graph(N);
				for (auto from : temp_list) {
					will_push_graph.emplace_back(Graph[from]);
				}
				decomposed_graph.emplace_back(will_push_graph);
				temp_list.clear();
			}
			color++;
		}
	}

	// ans: decomposed_graph

}
