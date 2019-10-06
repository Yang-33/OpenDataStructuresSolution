#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 12.2.1 & 12.2.2

int main() {

	const int N = 10;
	const int M = 30;
	{ // Incidence matrix
		vector<vector<int>> A(N, vector<int>(M, 0));
		// Space Complexity: O(NM)
		unordered_map<pair<int, int>, int>edge_number;
		vector<pair<int, int>>rev_edge_number;
		const pair<int, int> deleted = { -1,-1 };
		auto addedge = [&](int from, int to) {
			// Time Complexity: O(1)
			static int cnt = 0;
			A[from][cnt] = 1;
			A[to][cnt] = -1;
			edge_number[{from, to}] = cnt;
			rev_edge_number.emplace_back(from, to);
			cnt++;
		};

		auto removeEdge = [&](int from, int to) {
			// Time Complexity: O(1)
			if (edge_number.find({ from, to }) == edge_number.end())return;
			int edgenumber = edge_number[{from, to}];
			A[from][edgenumber] = 0;
			A[to][edgenumber] = 0;
			edge_number.erase({ from,to });
			rev_edge_number[edgenumber] = deleted;
		};

		auto hasEdge = [&](int from, int to) {
			// Time Complexity: O(1)
			if (edge_number.find({ from, to }) == edge_number.end())return false;
			int edgenumber = edge_number[{from, to}];
			return 	A[from][edgenumber] != 0 && A[to][edgenumber] != 0;
		};
		auto inEdges = [&](int v) {
			// Time Complexity: O(M)
			// get list: edge(j,i) of j
			vector<int>res;
			for (auto &it : rev_edge_number) {
				if (it.second == v)res.emplace_back(it.first);
			}
			return res;
		};
		auto outEdges = [&](int v) {
			// Time Complexity: O(M)
			// get list: edge(i,j) of j
			vector<int>res;
			for (auto &it : rev_edge_number) {
				if (it.first == v)res.emplace_back(it.second);
			}
			return res;
		};

		for (int i = 0; i < 5; i++) {
			{ // in
				addedge(i, (i + 2) % 5);
				addedge(i, (i + 3) % 5);
				addedge(i, i + 5);
			}
			{ // out
				addedge(i + 5, (i + 4) % 5 + 5);
				addedge(i + 5, ((i + 1) % 5) + 5);
				addedge(i + 5, i);
			}
		}
	}

}
