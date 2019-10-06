#include<bits/stdc++.h>
using namespace std;

int main() {

	{
		// dfs in textbook visits vertexes as below.
		// - make list we will visit.
		// - in dfs1, we visit list.front().
		// - in dfs2, we visit list.back().

		// Let's simulate from a as below graph.
		// a - b
		//  \ /
		//   c
		// dfs1: [a->b->c]
		// dfs2: [a->c->b]
	}

	{ // dfs2 as well as dfs1.
		auto dfs2 = [](Graph &g, int r) {
			char *c = new char[g.nVertices()];
			SLList<int>s;
			s.push(r);
			while (s.size() > 0) {
				int i = s.pop();
				if (c[i] == white) {
					c[i] = gray;
					ArrayStack<int>edges;
					g.outEdges(i, edges);
					for (int k = 0; k < edge.size(); k++) {
						s.push(edges.get(edge.size() - k - 1)); // Only we can change here.
					}
				}
			}
			delete[] c;
		};

	}

}
