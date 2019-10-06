#include<bits/stdc++.h>
using namespace std;

int main() {

	const int N = 10;

	{ // Adjacency matrix
		vector<vector<int>> A(N, vector<int>(N, 0));
		for (int i = 0; i < 5; i++) {
			{ // in
				A[i][(i + 2) % 5] = 1;
				A[i][(i + 3) % 5] = 1;
				A[i][i + 5] = 1;
			}
			{ // out
				A[i + 5][(i + 4) % 5 + 5] = 1;
				A[i + 5][((i + 1) % 5) + 5] = 1;
				A[i + 5][i] = 1;
			}
		}
	}

	{ // Adjacency list
		vector<vector<int>>A(N);
		for (int i = 0; i < 5; i++) {
			{ // in
				A[i].emplace_back((i + 2) % 5);
				A[i].emplace_back((i + 3) % 5);
				A[i].emplace_back(i + 5);
			}
			{ // out
				A[i + 5].emplace_back((i + 4) % 5 + 5);
				A[i + 5].emplace_back((i + 1) % 5 + 5);
				A[i + 5].emplace_back(i);
			}
		}
	}
}
