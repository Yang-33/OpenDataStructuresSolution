#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string>vs;

	string input;
	while (getline(cin, input)) {
		vs.emplace_back(input);
	}
	sort(vs.begin(), vs.end(), [](const string& L, const string& R) {
		if ((int)L.size() == (int)R.size()) {
			return L < R;
		}
		else {
			return (int)L.size() < (int)R.size();
		}
	});
	map<string, int>cnt; {
		for (auto &it : vs) {
			cnt[it]++;
		}
	}

	vs.erase(unique(vs.begin(), vs.end()), vs.end());

	for (auto &it : vs) {
		cout << it;
		if (cnt[it] > 1) {
			cout << " (cnt is:=" << cnt[it] <<")";
		}
		cout << endl;
	}
}