#include<bits/stdc++.h>
using namespace std;

int main() {
	// if the given sequence is "Match string",
	// the deepest bracket has its pair on next to itself.
	// Therefore we can paraphrase it with stack.

	const set<char> can_use{ '[',']','(',')','{','}' };

	auto is_correct_char = [&](char c) {
		return (can_use.find(c) != can_use.end());
	};
	auto is_matching_bracket = [](char L, char R) {
		if (L == '(' && R == ')')return true;
		if (L == '[' && R == ']')return true;
		if (L == '{' && R == '}')return true;
		return false;
	};

	string input; cin >> input;
	stack<char>st;

	bool is_match_string = true;
	for (auto &c : input) {
		if (!is_correct_char(c))is_match_string = false;
		if (st.size()) {
			if (is_matching_bracket(st.top(), c)) {
				st.pop();
			}
			else {
				st.push(c);
			}
		}
		else {
			st.push(c);
		}
	}
	is_match_string &= st.empty();
	cout << (is_match_string ? "OK" : "NG") << endl;

}