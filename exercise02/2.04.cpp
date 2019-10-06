#include<bits/stdc++.h>
using namespace std;

int main() {

	// shift |a| r times 
	auto rotate = [](vector<int>&a, int r) {
		auto b = a;
		int n = (int)a.size();
		for (int i = 0; i < n; i++) {
			b[(i + r) % n] = a[i];
		}
		a = b;
	};
}
