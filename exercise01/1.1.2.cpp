#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string>vs;
	auto output_vs = [&]() {
		reverse(vs.begin(), vs.end());
		for (auto &it : vs) {
			cout << it << endl;
		}
		vs.clear();
	};

	string input;
	while (getline(cin, input)) {
		vs.emplace_back(input);
		if ((int)vs.size() == 50) {
			output_vs();
		}
	}
	output_vs();

}