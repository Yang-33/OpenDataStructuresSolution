#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
	string input;
	unordered_set<string> uset;
	while (getline(cin, input)) {
		if (uset.find(input) == uset.end()) {
			cout << input << endl;
			uset.insert(input);
		}
	}
}