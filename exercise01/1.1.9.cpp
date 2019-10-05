#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string>vs;

	string input;
	while (getline(cin, input)) {
		vs.emplace_back(input);
	}


	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(vs.begin(), vs.end(), std::default_random_engine(seed));

	for (auto &it : vs) {
		cout << it << endl;
	}
}