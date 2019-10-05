#include<bits/stdc++.h>
using namespace std;

int main() {

	auto is_blank_line = [](const string& s) {
		bool is_blank = true;
		for (auto &c : s) {
			is_blank &= isspace(c);
		}
		return is_blank;
	};

	deque<string>vs;
	string input;
	while (getline(cin, input)) {
		if ((int)vs.size() < 42) {
			vs.push_back(input);
		}
		else {
			if (is_blank_line(input)) {
				cout << vs.front() << endl;
			}
			vs.pop_front();
			vs.push_back(input);
		}
	}
}