#include<bits/stdc++.h>
using namespace std;

int main() {
	stack<int> st; {
		for (auto it : { 4,3,2,1 }) {
			st.push(it);
		}
	}
	{ // check stack order
		auto st_copy = st;
		for (auto it : { 1,2,3,4 }) {
			assert(st_copy.top() == it);
			st_copy.pop();
		}
	}

	{ // use queue to make reverse stack.
		queue<int>q; {
			while (st.size()) {
				int topval = st.top(); st.pop();
				q.push(topval);
			}
		}
		assert(st.empty());
		while (q.size()) {
			int frontval = q.front(); q.pop();
			st.push(frontval);
		}
	}

	{ // check stack order
		auto st_copy = st;
		for (auto it : { 4,3,2,1 }) {
			assert(st_copy.top() == it);
			st_copy.pop();
		}
	}

}