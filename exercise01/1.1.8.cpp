#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string>odd_vs;

	string input;
	int linecnt = 0;
	while (getline(cin, input)) {
		if (linecnt % 2 == 0) {
			cout << input << endl;
		}
		else {
			odd_vs.emplace_back(input);
		}
		linecnt++;
	}

	for (auto &it : odd_vs) {
		cout << it << endl;
	}
}