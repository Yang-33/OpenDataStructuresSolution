#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string>vs;

	string input;
	while (getline(cin, input)) {
		vs.emplace_back(input);
	}
	
	reverse(vs.begin(), vs.end());
	for (auto &it : vs) {
		cout << it << endl;
	}
}